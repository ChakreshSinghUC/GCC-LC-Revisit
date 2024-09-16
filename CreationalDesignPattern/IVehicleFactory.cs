using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CreationalDesignPattern
{
    /// <summary>
    /// Define the Abstract Factory (IVehicleFactory)
    /// </summary>
    public interface IVehicleFactory
    {
        IVehicle CreateVehicle();
    }
}
