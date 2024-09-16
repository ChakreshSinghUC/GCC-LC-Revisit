using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreationalDesignPattern
{
    /// <summary>
    /// Concrete Product Implementations
    /// </summary>
    public class Bike : IVehicle
    {
        public string GetModelDetails()
        {
            return "This is a Bike";
        }
    }
}
