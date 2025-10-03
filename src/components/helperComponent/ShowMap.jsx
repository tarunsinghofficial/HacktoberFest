import React, { useState } from "react";
import {
  withScriptjs,
  withGoogleMap,
  GoogleMap,
  Marker,
  InfoWindow,
} from "react-google-maps";
import { faMapMarkedAlt } from "@fortawesome/free-solid-svg-icons";
import { connect } from "react-redux";
import { loadData } from "../../redux/authentication/localStorage";

let hotelData = loadData("hotelListData");
let location = loadData("location");
if (!location) {
  location = { lat: 12.9715987, lng: 77.5945627 };
}
//  points = [
//   { lat: 19.155001, lng: 72.849998, name: "hotel cacajaca", key: 1 },
//   { lat: 15.2993, lng: 74.124, name: "Juncus brachycarpus Engelm.", key: 2 },
//   { lat: 18.5408, lng: 73.8913, name: "Gossypianthus lanuginosus (Poir.) Moq.", key: 3 },
//   { lat: 12.9141, lng: 74.856, name: "Bartonia paniculata (Michx.) Muhl.", key: 4 },
// ];
class map extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      select: null,
    };
  }
  render() {
    return (
      <>
        <GoogleMap
          defaultZoom={10}
          defaultCenter={{ lat: location.lat, lng: location.lng }}
        >
          {hotelData &&
            hotelData.data.map((ele) => (
              <Marker
                key={ele.hotel_id}
                position={{
                  lat: Number(ele.location.lat),
                  lng: Number(ele.location.lon),
                }}
                onClick={() => {
                  this.setState({ select: ele });
                }}
                icon={{
                  url: ele.images.random[0],
                  scaledSize: new window.google.maps.Size(40, 40),
                }}
                // label="2000"
              />
            ))}
          {this.state.select && (
            <InfoWindow
              position={{
                lat: Number(this.state.select.location.lat),
                lng: Number(this.state.select.location.lon),
              }}
              onCloseClick={() => this.setState({ select: null })}
            >
              <div>
                <h2>{this.state.select.name}</h2>
                <h6>
                  Rooms price Rs.{this.state.select.rooms[0].actual_price}
                </h6>
              </div>
            </InfoWindow>
          )}
        </GoogleMap>
      </>
    );
  }
}
const WrappedMap = withScriptjs(withGoogleMap(map));
function Map() {
  return (
    <>
      <WrappedMap
        googleMapURL={
          "https://maps.googleapis.com/maps/api/js?v=3.exp&libraries=geometry,drawing,places&key=AIzaSyCcS0j7hDpSs-F4xDi2q6AkTD_sWqECR9M"
        }
        loadingElement={<div style={{ height: `100%` }} />}
        containerElement={<div style={{ height: `600px` }} />}
        mapElement={<div style={{ height: `100%` }} />}
      />
    </>
  );
}

// const mapStateToProps = (state) => ({
//     hotelData: state.auth.hotelListData
//   });

export default connect(null, null)(Map);
