const mqtt = require('mqtt');
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');
const port = new SerialPort({
  path: '/dev/cu.usbmodem14201',
  baudRate: 9600}
  );
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));
const client = mqtt.connect("mqtt://broker.hivemq.com:1883");

// Subscribe to Topic on MQTT Broker
client.on('connect', () => {
client.subscribe('/group10/messages');
console.log('mqtt connected \n');
});
const topic = '/group10/messages';

// Read the port data
port.on("open", () => {
console.log('serial port open');
});

// Got data from the Arduino
parser.on('data', data =>{
console.log('Retrieving data from Arduino \n');

// Publish data from Arduino
client.publish(topic, data, () => {
console.log('Publishing Arduino Code to MQTT Broker \n');
});
});

// Receive data from Arduino
client.on('message', (topic, message) => {
console.log(`Receiving Arduino Code from Broker \n`);
});
client.on('message', (topic, message) => {
if (topic == '/group10/messages') {
msg = `${message}\n`;

//Send data to the Arduino
port.write(msg, (err) => {
if (err) {
return console.log('Error on write: ', err.message);
}
console.log('Writting Code to Arduino \n');
});
}
});