package dsa;

import java.util.Arrays;
import java.util.Scanner;

public class target_mountain {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr={0,2,5,7,11,19,9,5,1};
        System.out.println("enter the target");
        int target=in.nextInt();
        int[] ans={-1,-1};
        ans[0]=position(arr,target,true);
        ans[1]=position(arr,target,false);
        System.out.println(Arrays.toString(ans));
    }
    static int position(int[] arr, int a,boolean i){
        int start=0;int end=arr.length-1;
        int p=peak(arr);
        if(a==arr[p]){
            return p;
        }
        if(i){
            end=p-1;
            while(start<=end){
                int mid=(start+end)/2;
                if (a<arr[mid]){
                    end=mid-1;
                } else if (a>arr[mid]) {
                    start=mid+1;
                } else if (a==arr[mid]) {
                    return mid;
                }
            }
        }else{
            start=p+1;
            while(start<=end){
                int mid=(start+end)/2;
                if (a>arr[mid]){
                    end=mid-1;
                } else if (a<arr[mid]) {
                    start=mid+1;
                } else if (a==arr[mid]) {
                    return mid;
                }
            }
        }return -1;
    }
    static int peak(int[] arr){
        int start=0;
        int end =arr.length-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }if(arr[mid]>arr[mid+1]){
                end=mid;
            }
        }return start;
    }
}
