// See https://aka.ms/new-console-template for more information
using CreationalDesignPattern;

Console.WriteLine("Let's manufacture some vehicles!");

var carFactory = new CarFactory();
var system = new VehicleManufacturingSystem(carFactory);
system.ManufactureVehicle();  // Output: "This is a Car"

var bikeFactory = new BikeFactory();
system = new VehicleManufacturingSystem(bikeFactory);
system.ManufactureVehicle();  // Output: "This is a Bike"