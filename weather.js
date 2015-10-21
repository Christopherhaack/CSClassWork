function onWeather(err, data) {
  if(err) {
    var el = document.getElementById("error");
    el.innerHTML = "there was an error with getting the weather";
    document.getElementById("results").style.display = "none";
    document.getElementById("response").style.display = "";
    el.style["display"] = "";
    return;
  }
  var errorEl = document.getElementById("error");
  errorEl.innerHTML = "";
  errorEl.style["display"] = "none";

  var el = document.getElementById('response');

  var temp = data.main.temp;
  document.getElementById("temp").innerHTML = temp + " &deg;F";

  var windspeed = data.wind.speed;
  var windEl = document.getElementById('windspeed');
  windEl.innerHTML = windspeed + " mph";


  var iconUrl = "http://openweathermap.org/img/w/" + data.weather[0].icon + ".png";
  var iconEl = document.getElementById("icon");

  var img=document.createElement("img");
  img.setAttribute('src', iconUrl);
  iconEl.innerHTML = "";
  iconEl.appendChild(img);

  var locationEl = document.getElementById("location");
  locationEl.innerHTML = data.name;
  el.style["display"] = "block";
  var resultsEl = document.getElementById("results");
  resultsEl.style["display"] = "block";

}

function onZipCode(err, data) {
  if(err) {
    
    var el = document.getElementById("error");
    el.innerHTML = "there was an error with getting the zipcode";
    document.getElementById("results").style.display = "none";
    document.getElementById("response").style.display = "";
    el.style["display"] = "";
    return;
  }
  var firstMatch = data.places[0];
  var country = data["country abbreviation"];
  var city = firstMatch["place name"];
  var state = firstMatch["state"];

  var url = "http://api.openweathermap.org/data/2.5/weather?units=imperial&q=";
  url += city + "," + state + "," + country;
   AJAX.getJSON(url, onWeather); 
}

function getWeather(e) {
  e.preventDefault(); // stop submit
  var zipCode = document.getElementById("zipCode").value;
  if(!zipCode) {
    var el = document.getElementById("error");
    el.innerHTML = "there was an error with getting the weather";
    document.getElementById("results").style.display = "none";
    document.getElementById("response").style.display = "";
    el.style["display"] = "";
    
    return;
  }
  var url = "http://api.zippopotam.us/us/" + zipCode;
  AJAX.getJSON(url, onZipCode); 
}
