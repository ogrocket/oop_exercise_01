class FN{
private:
    double L, X, R;
    FN(double L_in, double X_in, double R_in){
        L = L_in;
        X = X_in;
        R = R_in;
    };
public:
    FN(double X_in, double e_in){
        L = X_in - e_in;
        X = X_in;
        R = X_in + e_in;
    };

    double get_l(){return L;}
    double get_x(){return X;}
    double get_r(){return R;}
    double get_er(){return R-X;}
    double get_el(){return X-L;}

    void printer(){
        printf("(%.3f, %.3f, %.3f)",L, X, R);
    }

    FN operator+ (FN op2){
        FN res(L + op2.L, X + op2.X, R + op2.R);
        return res;
    }
    FN operator- (FN op2){
        FN res(L-op2.R, X - op2.X, R - op2.L);
        return res;
    }
    FN operator*(FN op2){
        FN res(L * op2.L, X * op2.X, R * op2.R);
        return res;
    }
    FN operator/(FN op2){
        if (op2.X > 0){
            FN res(L / op2.R, X / op2.X, R / op2.L);
            return res;
        }
        else{
            printf("Error\n");
            FN err(0,0);
            return err;
        }
    }
    FN reverse_fn(){
        if (X > 0){
            FN res(1 / R, 1 / X, 1 / L);
            return res;
        }
        else{
            printf("Error\n");
            FN err(0,0);
            return err;
        }
    }

    bool operator>(FN op2){
        return (X > op2.X);
    }
    bool operator>=(FN op2){
        return (X >= op2.X);
    }
    bool operator<(FN op2){
        return (X < op2.X);
    }
    bool operator<=(FN op2){
        return (X <= op2.X);
    }
    bool operator==(FN op2){
        return (X == op2.X);
    }
    bool operator!=(FN op2){
        return (X != op2.X);
    }
};
