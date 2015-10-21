var Promise = require("bluebird");
// Convert fs library to a version that supports promises.
var fs = Promise.promisifyAll(require("fs"));
var employees = fs.readFileAsync("employees.json");
var bonuses = fs.readFileAsync("bonuses.json");
var functions = require("./functions")
Promise.all([employees, bonuses]).spread(function(employees, bonuses) {
  employees = employees.toString();
  bonuses = bonuses.toString();
  var employeesArray = JSON.parse(employees);
  var bonusesArray = JSON.parse(bonuses);
  newEmployees = JSON.stringify(functions.calculateBonuses(employeesArray, bonusesArray));
    fs.writeFile('newEmployees.JSON', newEmployees, function (err) {
  	if (err) throw err;
	});
});