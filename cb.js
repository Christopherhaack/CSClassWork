var fs = require("fs");
var employees = null;
var bonuses = null;
var functions = require("./functions")
fs.readFile("employees.json", function(err, data) {
  if (err) {
    throw err;
  }
  var employees = data.toString();
  fs.readFile("bonuses.json", function(err, data) {
    if (err) {
      throw err;
    }
    var bonuses = data.toString();
    var employeesArray = JSON.parse(employees);
    var bonusesArray = JSON.parse(bonuses);
    newEmployees = JSON.stringify(functions.calculateBonuses(employeesArray, bonusesArray));
    fs.writeFile('newEmployees.JSON', newEmployees, function (err) {
  	if (err) throw err;
	});
	functions.logBonuses(newEmployees);
  });
});