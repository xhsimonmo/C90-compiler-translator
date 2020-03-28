int f(int a, int b){
    return a + b ;
}

int g(int a) {
    return a;
}

int main(){
    int a = 1;
    int b = 2;
    return f(g(a), b);
}
