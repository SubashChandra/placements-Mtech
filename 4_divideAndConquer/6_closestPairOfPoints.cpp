#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<cfloat>


using namespace std;

struct point
{
	int x;
	int y;
};

typedef struct point Point;

int compareX(Point p1, Point p2)
{
	return p1.x<p2.x;
}

int compareY(Point p1, Point p2)
{
	return p1.y<p2.y;
}

float dist(Point p1, Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float bruteForce(vector<Point> points,int l, int r)
{
	float min=FLT_MAX;
	int i,j,n;

	for(i=l;i<=r-1;i++)
	{
		for(j=i+1;j<=r;j++)
		{
			if(dist(points[i],points[j])<min)
				min=dist(points[i],points[j]);
		}
	}
	return min;
}


float stripClosest(vector<Point> strip,float d)
{
	sort(strip.begin(), strip.end(),compareY);
	int i,j;
	float minDist=d;
	int n=strip.size();
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n && (strip[j].y-strip[i].y)< d ;j++)
		{
			if(dist(strip[i],strip[j])<minDist)
				minDist=dist(strip[i], strip[j]);
		}
	}
	return minDist;
}




float auxFunc(vector<Point> points, int l, int r)
{

	if((r-l+1)<=3)
		return bruteForce(points,l,r);
	
	int mid=(l+r)/2;
	Point midPoint=points[mid];

	float lDist=auxFunc(points,l,mid);
	float rDist=auxFunc(points,mid+1,r);

	float dist=min(lDist,rDist);
	vector<Point> strip;
	int i;
	for(i=0;i<points.size();i++)
	{	
		if(abs(points[i].x-midPoint.x) <dist)
			strip.push_back(points[i]);
	}

	return min(dist, stripClosest(strip,dist));
}





float closest(vector<Point> points)
{
	sort(points.begin(),points.end(),compareX);
	return auxFunc(points,0,points.size()-1);
}


int main()
{
	int n;
	cin>>n;
	vector<Point> points(n);
	int i,x,y;
	for(i=0;i<n;i++)
	{
		cin>>points[i].x>>points[i].y;
	}
	cout<<closest(points)<<endl;	
	return 0;
}
