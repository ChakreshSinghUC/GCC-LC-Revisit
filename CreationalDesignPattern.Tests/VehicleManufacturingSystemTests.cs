using CreationalDesignPattern;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Moq;

namespace VehicleManufacturingSystemUnitTests
{
    [TestClass]  // Marks this class as a test class
    public class VehicleManufacturingSystemTests
    {
        [TestMethod]  // Marks this method as a test method
        public void ManufactureVehicle_CallsCreateVehicleOnFactory()
        {
            // Arrange
            var mockVehicleFactory = new Mock<IVehicleFactory>();
            var mockVehicle = new Mock<IVehicle>();

            mockVehicleFactory.Setup(f => f.CreateVehicle()).Returns(mockVehicle.Object);
            var system = new VehicleManufacturingSystem(mockVehicleFactory.Object);

            // Act
            system.ManufactureVehicle();

            // Assert
            mockVehicleFactory.Verify(f => f.CreateVehicle(), Times.Once);
        }

        [TestMethod]
        public void ManufactureVehicle_PrintsCorrectVehicleDetails()
        {
            // Arrange
            var mockVehicleFactory = new Mock<IVehicleFactory>();
            var mockVehicle = new Mock<IVehicle>();
            mockVehicle.Setup(v => v.GetModelDetails()).Returns("Mocked Vehicle");

            mockVehicleFactory.Setup(f => f.CreateVehicle()).Returns(mockVehicle.Object);
            var system = new VehicleManufacturingSystem(mockVehicleFactory.Object);

            // Act
            system.ManufactureVehicle();

            // Assert
            mockVehicle.Verify(v => v.GetModelDetails(), Times.Once);
        }
    }
}
