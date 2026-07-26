struct point{
    double x,y,z;
    bool operator < (const point& a) const{
        if(x!=a.x)return x<a.x;
        return y<a.y;
    }
    bool operator == (const point& a) const{
        return x==a.x&&y==a.y&&z==a.z;
    }
    point operator + (const point&a) const {
        return {x+a.x,y+a.y,z+a.z};
    }
    point operator - (const point&a) const{
        return {x-a.x,y-a.y,z+a.z};
    }
};
point cross(point a,point b){
    point c;
    c.x=a.y*b.z-a.z*b.y;
    c.y=a.z*b.x-a.x*b.z;
    c.z=a.x*b.y-a.y*b.x;
    return c;
}
