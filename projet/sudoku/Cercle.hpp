class Cercle
{
private :
  float m_cX,m_cY;
  float m_r;

public :
  Cercle();
  ~Cercle();
  void move(float dx, float dy);
  void zoom(float R);
  float area();
};
