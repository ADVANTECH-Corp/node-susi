// Module node-SUSI demo
// Reads CPU Temperature from ADVANTECH platform

var sensorLib = require('../node-susi');
var cpuIndex = 0;

var sensor = {
    read: function () {
        var readout = sensorLib.getTemperature(cpuIndex);
        console.log('Temperature: ' + readout + 'C');
        setTimeout(function () {
            sensor.read();
        }, 2000);
    }
};

sensor.read();
