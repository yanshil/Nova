//!#####################################################################
//! \file Point_Cloud.h
//!#####################################################################
// Class Point_Cloud
//######################################################################
#ifndef __Point_Cloud__
#define __Point_Cloud__

#include <nova/Tools/Arrays/Array.h>
#include <nova/Tools/Vectors/Vector.h>

namespace Nova{
template<class T,int d>
class Point_Cloud
{
    using TV                    = Vector<T,d>;

  public:
    Array<TV> points;

    Point_Cloud() {}

    Point_Cloud(const Array<TV>& points_input)
        :points(points_input)
    {}

    ~Point_Cloud() {}

    void Resize_Vertices(const size_t size)
    {points.resize(size);}

    void Set_Vertex(const unsigned index,const TV& X)
    {
        assert(index>=0 && index<points.size());
        points[index]=X;
    }

    unsigned Add_Vertex(const TV& X)
    {
        points.Append(X);
        return points.size();
    }
};
}
#include <nova/Geometry/Read_Write/Topology/Read_Write_Point_Cloud.h>
#endif
