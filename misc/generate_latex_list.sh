#!/bin/bash

org_path="/home/garrido/Teachdir/C++"
org_file="${org_path}/notes/notes.org"
org_date="2015/2016"
if [ ! -z $1 ]; then
    org_date=$1
fi

function generate_header ()
{
    cat << EOF >> $1
\documentclass[a4paper]{article}
\usepackage[utf8]{inputenc}
\usepackage[frenchb]{babel}
\usepackage{pifont}
\usepackage{graphicx}
\usepackage[table]{xcolor}
\usepackage{comment}
\usepackage{longtable}
\usepackage[hmargin=1cm, vmargin=1cm]{geometry}
\usepackage{array,etoolbox}
\preto\tabular{\setcounter{magicrownumbers}{0}}
\newcounter{magicrownumbers}
\newcommand\rownumber{\stepcounter{magicrownumbers}\arabic{magicrownumbers}}

\makeatletter
\newcommand{\boldarrayrulewidth}{1\p@}
\def\bhline{\noalign{\ifnum0=\`}\fi\hrule \@height
\boldarrayrulewidth \futurelet \@tempa\@xhline}
\def\@xhline{\ifx\@tempa\hline\vskip \doublerulesep\fi
      \ifnum0=\`{\fi}}
\newcommand{\br}{\ms\bhline\ms}
\newcommand{\mr}{\ms\hline\ms}
\newcommand{\ms}{\noalign{\vspace{3\p@ plus2\p@ minus1\p@}}}
\newcommand{\bs}{\noalign{\vspace{6\p@ plus2\p@ minus2\p@}}}
\newcommand{\ns}{\noalign{\vspace{-3\p@ plus-1\p@ minus-1\p@}}}
\newcommand{\es}{\noalign{\vspace{6\p@ plus2\p@ minus2\p@}}\displaystyle}%
\makeatother

\definecolor{upsud_blue}{RGB}{0,72,112}
\definecolor{upsud_green}{RGB}{132,184,24}
\definecolor{upsud_gray}{RGB}{107,108,110}
\definecolor{upsud_red}{RGB}{221,42,43}
\definecolor{upsud_brown}{RGB}{192,128,64}
\definecolor{upsud_violet}{RGB}{136,64,192}
\definecolor{lightgray}{gray}{0.9}

\usepackage[absolute,overlay]{textpos}
\setlength{\TPHorizModule}{1mm}
\setlength{\TPVertModule}{1mm}

\usepackage{hyperref}
\hypersetup{
  backref,
  pagebackref,
  naturalnames=true,
  colorlinks=true,
  urlbordercolor={0.0 0.2823 0.43921},
  urlcolor=upsud_green
}

\begin{document}
\pagestyle{empty}
\sf\color{upsud_gray}
  \begin{textblock}{0}(160,0)
    \includegraphics[width=4cm]{${org_path}/misc/logo_upsud}
  \end{textblock}
  {\LARGE \textcolor{upsud_blue}{Liste étudiants - Master 1 C++ ${org_date}}}

  \vspace{+0.2cm}
         {\normalsize \textcolor{upsud_blue}{Contact : Xavier Garrido \href{xavier.garrido@u-psud.fr}{\ding{41} xavier.garrido@u-psud.fr} \ding{37} 01 64 46 84 28}}

EOF
}

function generate_footer ()
{
    cat << EOF >> $1
\end{document}
EOF
}

function generate_student_list ()
{
    sed -n '/*.*'${org_date%%/*}'/,/*.*/p' ${org_file} > ${org_file}.tmp
    cat << EOF >> $1
\begin{comment}
#+ORGTBL: SEND listing orgtbl-to-latex :splice t :hline "\\\\bs"
EOF
    sed -i \
        -e 's/\_/xxx/g' \
        -e 's/°/$^\\circ$/g' \
        -e '/\*/d' -e '/|-/d' -e '/Email/d' -e '/^$/d' -e '/^\#/d' \
        ${org_file}.tmp
    cat ${org_file}.tmp >> $1
    local nbr_row=$(cat ${org_file}.tmp | head -1 | awk -F'|' '{print NF-2}')
    cat << EOF >> $1
\end{comment}

  \rowcolors{1}{}{lightgray}
  \begin{longtable}{@{\makebox[3em][r]{\rownumber\space}}|
EOF
    for i in $(seq 1 $nbr_row); do echo -ne "l" >> $1; done
    cat << EOF >> $1
}
  % BEGIN RECEIVE ORGTBL listing
  % END RECEIVE ORGTBL listing
  \end{longtable}
EOF
    rm ${org_file}.tmp*
}

function generate_picture_list ()
{
    echo "\vspace{0.5cm}" >> $1
    echo "{\Large \textcolor{upsud_blue}{\ding{217} Trombinoscope}}" >> $1
    local modulo=5
    function --table-header()
    {
        echo "\rowcolors{1}{}{}" >> $1
        echo "\begin{longtable}{*{$modulo}{>{\centering\arraybackslash}p{3cm}}}" >> $1
    }
    function --table-footer()
    {
        echo "\end{longtable}" >> $1

    }

    local cnt=1
    echo "Generate table for ${org_date}"
    names="$(sed -n '/*.*'${org_date%%/*}'/,/*.*/p' ${org_file} | awk -F'|' '{
        if ( $0 ~ /[]@[]/ && $0 !~ /#/ ) {
          gsub(/^[ \t]+|[ \t]+$/, "", $2)
          gsub(/^[ \t]+|[ \t]+$/, "", $3)
          gsub(" ", "-", $2)
          gsub(" ", "-", $3)
          print tolower($3)"."tolower($2)
        }
    }')"
    local line_name=
    let cnt=1
    --table-header $1
    for name in ${names}
    do
        local adonis_pics_path="${org_path}/misc/pictures/${org_date/\//_}"
        local nname=$(echo $name | iconv -f utf8 -t ascii//TRANSLIT)
        echo "Getting picture for $nname "
        if [ -f ${adonis_pics_path}/${nname}.jpg ]; then
            echo -n "\includegraphics[width=3cm]{${adonis_pics_path}/{${nname}}.jpg}" >> $1
        fi
        local nnname="$(echo $name | awk -F'.' '{print $1,$2}' | sed 's/[^ _-]*/\u&/g')"
        line_name+="$nnname"
        if [ $(($cnt % $modulo)) == 0 ]; then
            echo "\\\\" >> $1
            echo "${line_name}\\\\" >> $1
            line_name=
        else
            echo -n "&" >> $1
            line_name+="&"
        fi
        let cnt++
    done
    echo "\\\\${line_name}\\\\" >> $1
    --table-footer $1
}

function generate_pdf ()
{
    emacsclient -n \
                --eval '(with-temp-buffer
              (insert-file-contents "'${latex_file}'")
              (org-table-map-tables (lambda () (orgtbl-send-table)))
              (write-file "'${latex_file}'"))'
    sed -i -e 's/xxx/\\_/g' ${latex_file}
    pdflatex -halt-on-error $1 && pdflatex -halt-on-error $1
    if [ $? -eq 0 ]; then
        xdg-open $(basename ${1/.tex/.pdf}) &
    fi
}

latex_file="/tmp/liste_${org_date/\//_}.tex"
if [ -f ${latex_file} ];then
    rm -f ${latex_file}
fi

generate_header       ${latex_file}
generate_student_list ${latex_file}
generate_picture_list ${latex_file}
generate_footer       ${latex_file}
generate_pdf          ${latex_file}

# generate_header       ${trombi_file}
# generate_footer       ${trombi_file}
# generate_pdf          ${trombi_file}
