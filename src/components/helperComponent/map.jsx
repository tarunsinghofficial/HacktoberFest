
// import React,{useState} from 'react'
// import {
//     withScriptjs,
//     withGoogleMap,
//     GoogleMap,
//     Marker,
//     InfoWindow
//   } from "react-google-maps";

// //   var points = [
// //     { lat: 42.02, lng: -76.01, name:"hotel cacajaca", key:1 },
// //     { lat: 42.03, lng: -77.02,name:"Juncus brachycarpus Engelm.",key:2},
// //     { lat: 41.03, lng: -75.04,name:"Gossypianthus lanuginosus (Poir.) Moq.",key:3 },
// //     { lat: 42.05, lng: -78.02,name:"Bartonia paniculata (Michx.) Muhl." ,key:4}
// // ]
// export default class map extends React.Component{
//     constructor(props){
//         super(props)
//         this.state={
//             select:null
//         }
//     }
//     render(){
//         const {hotelData} = this.props
//         console.log(hotelData,"map data")
        
//         return(
//             hotelData && hotelData.status && (

//             <>
//                     <GoogleMap
//                     defaultZoom={5}
//                     defaultCenter={{ lat: 12.76, lng: 77.5946 }}>
//                         {
//                           hotelData && hotelData.status &&  hotelData.data.map(ele=>(
                            
//                                 <Marker key={ele.hotel_id} position={{ lat: Number(ele.location.lat), lng: Number(ele.location.lon) }}
//                                 onClick={()=>{
//                                     console.log(ele)
//                                         this.setState({select:ele})
//                                     }}
//                                     // icon={{
//                                     //     url:"https://i.pinimg.com/600x315/5e/51/0c/5e510c69169756774ee36eea82da3a1a.jpg",
//                                     //     scaledSize:new window.google.maps.Size(40,40),
//                                     // }}
//                                     // label="2000"
//                                 />
//                             ))
//                         }
//                         {
//                             this.state.select && (
//                                 <InfoWindow
//                                  position={{ lat: Number(this.state.select.location.lat), lng: Number(this.state.select.location.lon) }}
//                                   onCloseClick={()=>this.setState({select:null})}>
//                                       <div>

//                                       <h2>{this.state.select.name}</h2>
//                                       <h6>{this.state.select.rooms[0].actual_price}</h6>
//                                       </div>
//                                 </InfoWindow>
//                             )
//                         }
//                 </GoogleMap>
//             </>
//             )
//         )
//     }
    
// }

