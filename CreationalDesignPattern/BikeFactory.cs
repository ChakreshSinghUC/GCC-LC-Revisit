using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreationalDesignPattern
{
    /// <summary>
    /// Implement Concrete Factory
    /// </summary>
    public class BikeFactory : IVehicleFactory
    {
        public IVehicle CreateVehicle()
        {
            return new Bike();
        }
    }
}
