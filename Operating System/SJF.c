#include<stdio.h>
#define p_item 4
int main(){
    char *pid[p_item] = {"p1","p2","p3","p4"};
    int at[p_item] = {4,1,0,4};
    int bt[p_item] = {6,10,4,3};

    for(int k=0;k<4;k++){
        for (int i=0;i<4-k-1;i++){
            if (at[i] > at[i+1] || (at[i] == at[i+1] && bt[i] > bt[i+1])){
                char *itm = pid[i];
                pid[i] = pid[i+1];
                pid[i+1] = itm;
                int tem = at[i];
                at[i] = at[i+1];
                at[i+1] = tem;
                tem = bt[i];
                bt[i] = bt[i+1];
                bt[i+1] = tem;
            }
        }}

    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    int at_=0,bt_=0, ct_= 0,wt_=0,tat_=0,st_=0;
    for (int i=0; i<p_item;i++){
        at_=at[i];
        bt_=bt[i];
        if(i==0){
            st_=at_;
        }
        ct_=st_+bt_;
        wt_=st_-at_;
        tat_=bt_+wt_;
        if ( ct_>at[i+1]){
            st_=ct_;
        }else{
            st_=at[i+1];
        }
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",pid[i],at_,bt_,ct_,wt_,tat_);
    }
}