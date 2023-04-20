//作业：
//读取10个整型数据 12 63 58 95 41 35 65 0 38 44，让通过冒泡排序，快速排序，插入排序，分别对改组数据进行排序

#include <iostream>

#define length 10
void BubbleSort(int*arr,int len);
void QuickSort(int*arr,int low,int high);
void InsertionSort(int*arr,int len);
int partition(int*arr,int low,int high);
void printARR(int*arr,int len);

int main() {
    int*arr1=(int *)calloc(length,sizeof(int ));
    int*arr2=(int *)calloc(length,sizeof(int ));
    int*arr3=(int *)calloc(length,sizeof(int ));
    for(int i=0;i<length;i++){
        scanf("%d",&arr1[i]);
        arr2[i]=arr1[i];
        arr3[i]=arr1[i];
    }
    //冒泡排序
    BubbleSort(arr1,length);
    printf("\n--------BUBBLE--------\n");
    printARR(arr1,length);
    //快速排序
    QuickSort(arr2,0,length-1);
    printf("\n--------QUICK--------\n");
    printARR(arr2,length);
    //直接插入排序
    InsertionSort(arr3,length);
    printf("\n--------INSERTION--------\n");
    printARR(arr3,length);

    return 0;
}

void printARR(int*arr,int len){
    for(int i=0;i<len;i++)
        printf("%-3d",arr[i]);
}

void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}

void BubbleSort(int*arr,int len){
    int i=0,j=0;
    bool flag=true;
    for(i=0;i<len-2;i++){
        flag= true;
        for(j=len-1;j>i;j--){
            if(arr[j]<arr[j-1]) {
                swap(arr[j], arr[j - 1]);
                flag=false;
            }
        }
        if(flag)
            return;
    }
}
int partition(int*arr,int low,int high){
    int pivot=arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivot)
            high--;
        arr[low]=arr[high];
        while(low<high&&arr[low]<=pivot)
            low++;
        arr[high]=arr[low];
    }
    arr[low]=pivot;
    return low;
}

void QuickSort(int*arr,int low,int high){
    if(low<high){
        int pivot_pos= partition(arr,low,high);
        QuickSort(arr,low,pivot_pos-1);
        QuickSort(arr,pivot_pos+1,high);
    }
}

void InsertionSort(int*arr,int len){
    int i=0,j=0;
    int pivot=0;
    for(i=1;i<len;i++){
        pivot=arr[i];
        for(j=i;j>0&&arr[j-1]>pivot;j--){
            arr[j]=arr[j-1];
        }
        arr[j]=pivot;
    }
}

