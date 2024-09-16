using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreationalDesignPattern
{
    /// <summary>
    /// Client Code (Factory usage)
    /// </summary>
    public class VehicleManufacturingSystem
    {
        private readonly IVehicleFactory _vehicleFactory;
        public VehicleManufacturingSystem(IVehicleFactory vehicleFactory)
        {
            _vehicleFactory = vehicleFactory;
        }

        public void ManufactureVehicle()
        {
            IVehicle vehicle = _vehicleFactory.CreateVehicle();
            Console.WriteLine(vehicle.GetModelDetails());
        }
    }
}
