using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreationalDesignPattern
{
    /// <summary>
    /// Concreate Product Implementation
    /// </summary>
    public class Car : IVehicle
    {
        public string GetModelDetails()
        {
            return "This is a Car";
        }
    }
}
