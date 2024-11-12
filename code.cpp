class Vehicle{
    private:
      int vehicleNUmber;
    public:
      void display(){
        cout<<"Vehicle"<<vehicleNUmber;
      }
      
};

class car:public Vehicle{
    private:
      int vehicleNumber;
    public:
     void display() override{
        cout<<"vehicle"<<vehicleNumber;
     }        
};

int main(){
    Vehicle car1
}