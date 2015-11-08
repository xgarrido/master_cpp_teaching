#!/bin/bash

org_path="/home/garrido/Teachdir/C++"
org_file="${org_path}/notes/notes.org"
org_date="2015/2016"

adonis_http="http://adonis.u-psud.fr/users"
adonis_pics_path="${org_path}/misc/pictures/${org_date/\//_}"
mkdir -p ${adonis_pics_path}

echo "Grab pictures for ${org_date}"
names="$(sed -n '/*.*'${org_date%%/*}'/,/*.*/p' ${org_file} | awk -F'|' '{
        if ( $0 ~ /[]@[]/ && $0 !~ /#/ ) {
          gsub(/^[ \t]+|[ \t]+$/, "", $2)
          gsub(/^[ \t]+|[ \t]+$/, "", $3)
          gsub(" ", "-", $2)
          gsub(" ", "-", $3)
          print tolower($3)"."tolower($2)
        }
    }')"
for name in ${names}
do
    nname=$(echo $name | iconv -f utf8 -t ascii//TRANSLIT)
    echo -ne "Getting picture for $nname "
    if [ -f ${adonis_pics_path}/${nname}.jpg ]; then
        echo "-> already downloaded"
        continue
    fi
    for i in 0 1 2 3
    do
        http_path=${adonis_http}/sl$i/${nname:0:1}/${nname}/
        wget -r --no-parent -A "*.jpg" ${http_path} -P /tmp > /dev/null 2>&1
        if [ $? -eq 0 ]; then
            echo "-> picture found"
            cp $(ls -1t /tmp/${http_path/http:\/\//}*.jpg | head -1) ${adonis_pics_path}/${nname}.jpg
            break
        elif [ $i -eq 3 ]; then
            echo "-> picture not found"
        fi
    done
done
