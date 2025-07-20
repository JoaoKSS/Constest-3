#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    int quant = 0,aux;
    cin >> quant;

    while(quant--){
        cin >> aux;
        vec.push_back(aux);
    }
    if(quant == 1){
        cout << 1 << endl;
        return 0;
    }

    quant = vec.size();
    int lastV = vec[quant-1];
    int elemCount = 1;
    int maiorSeq = 1;

    quant-=1;

    while(quant--){
        if(vec[quant] < lastV){
            elemCount++;
            lastV = vec[quant];
            if(elemCount > maiorSeq){
                maiorSeq=elemCount;
            }
        }else{
            lastV = vec[quant];
            elemCount = 1;
        }

    }
    
    cout << maiorSeq << endl;
    return 0;
}