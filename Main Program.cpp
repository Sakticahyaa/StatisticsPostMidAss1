#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int data[60];
    int i, j, k=0;
    double mean, median, std_dev, var, total=0;
    double sequence[60];
    int freq[99][2];


//input data
    cout<<"Input data: ";
    for(i=0;i<60;i++)
    {
        cin>>data[i];
    }


//initializing an empty frequenyc array
    for(i=0;i<99;i++)
    {
        freq[i][0]=i+1;
        freq[i][1]=0;
    }


//computing frequency
    for(i=0;i<60;i++)
    {
        for(j=0;j<99;j++)
        {
            if (data[i]==j)
            {
                freq[j-1][1]++;
                break;
            }
        }
        j=0;
    }


//display frequency
    for(i=0;i<99;i++)
    {
        if (freq[i][1]!=0)
        {
            for(j=0;j<2;j++)
            {
                cout<<freq[i][j]<<"\t";
            }
            j=0;
            cout<<endl;
        }
    }    


//sequencing data
    for(i=0;i<99;i++)
    {
        if (freq[i][1]!=0)
        {
            for(j=0;j<freq[i][1];j++)
            {
                sequence[k]=freq[i][0];
                k++;
            }
        }
    }


//median
    for(i=0;i<60;i++)
    {
        total=total+sequence[i];
    }
    mean=total/60;


//median
    median=(sequence[30]+sequence[29])/2;


//variance
    for(i=0;i<60;i++)
    {
        var=var+((sequence[i]-mean)*(sequence[i]-mean));
    }
    var=var/60;


//standard deviation
    std_dev=sqrt(var);



//displaying data
    cout<<"mean: "<<mean;
    cout<<"\nmedian: "<<median;
    cout<<"\nstd dev: "<<std_dev;
    cout<<"\nvariance: "<<var;

    return 0;
}
