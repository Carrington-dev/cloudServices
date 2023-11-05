class Model{
    private String name;
    Model(String myName){
        this.name  = myName;
    }

    public String getModel(){
        return this.name;
    }
}

class Car{
    public int id;
    public int year = 2023;
    public String title;
    public Model model;

    Car(int myId, String myTitle, Model myModel){
        this.id = myId;
        this.title = myTitle;
        this.model = myModel;
    }
    
    public void print(){
        System.out.println("Car-id: " + this.id);
        System.out.println("Car: " +  this.title);
        System.out.println("Year: " + this.year);
        System.out.println("Model: " + this.model.getModel());
    }
}

class MyPogram{
    public static void main(String[] args){
        Car car = new Car(12, "New Toyota C-HR For Sale At 20 Off", new Model("C-HR"));
        car.print();
    }
}