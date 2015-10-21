var fs = require("fs");
var calculateBonuses = function(employees, bonuses) {
	var newEmployees = [];
	for (var i = 0; i < employees.length; i++) {
		worker = employees[i];
		if(bonuses[worker["id"]]) {
			newSalary = worker["salary"] + 1000 * worker["yearsWorking"];
			worker["salary"] = newSalary;
			newEmployees.push(worker);
		}
	}
	return newEmployees;
};
var logBonuses = function(newEmployees) {
	nEmployees = JSON.parse(newEmployees);
	var logInfo = ""
	for (var i = 0; i < nEmployees.length; i++) {
		worker = nEmployees[i];
		name = worker["name"];
		fullName = name["first"] + " " + name["last"];
		logInfo = logInfo + fullName + " " + worker["salary"] + "\n";
		
	}
	fs.writeFile('log.txt', logInfo, function (err) {
  		if (err) throw err;
  		console.log("proccess is complete");
	});
}

exports.calculateBonuses = calculateBonuses;
exports.logBonuses = logBonuses;