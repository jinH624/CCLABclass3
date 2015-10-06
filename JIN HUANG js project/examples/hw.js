$(document).ready(function(){
	$("#demosMenu").change(function(){
	  window.location.href = $(this).find("option:selected").attr("id") + '.html';
	});
});
var panorama;
function initialize() {

	 var styles = [
    {
      stylers: [
        { hue: "#e4571b" },
        { saturation: 70 }
      ]
    },{
      featureType: "road",
      elementType: "geometry",
      stylers: [
        { lightness: 30 },
        { visibility: "on" }
      ]
    },{
      featureType: "road",
      elementType: "labels",
      stylers: [
        { visibility: "off" }
      ]
    }
  ];

   var styledMap = new google.maps.StyledMapType(styles,
    {name: "Styled Map"});

  var fenway = {lat: 31.226701, lng: 121.4918754};
  var map = new google.maps.Map(document.getElementById('map'), {
    center: fenway,
    zoom: 9
  });

  //Associate the styled map with the MapTypeId and set it to display.
  map.mapTypes.set('map_style', styledMap);
  map.setMapTypeId('map_style');

  var panorama = new google.maps.StreetViewPanorama(
      document.getElementById('pano'),
      {
        position: fenway,
        pov: {heading: 105, pitch: 15},
        zoom:0.3
      });
  map.setStreetView(panorama);
}
