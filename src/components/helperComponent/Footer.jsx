import React, { Component } from "react";
import styles from "./Footer.module.css";

export default class Footer extends Component {
  render() {
    return (
      <div className="container-fluid " id={styles.bgColor}>
        <div className="row" id={styles.footerHead}>
          <div className="col-12" id={styles.footerLeft}>
            <span>
              <img src="/images/log_size.jpg" alt="" />
            </span>
            <span>The World's Fastest Growing Hotel Chain</span>
          </div>
        </div>
        <div className="row" id={styles.des}>
          <div className="col-4  d-flex flex-column" id={styles.contact}>
            <span>About us</span>
            <span>Partner With Us</span>
            <span>Terms & Conditions</span>
            <span>Privacy Policy</span>
            <span>Guest Policy</span>
          </div>
          <div className="col-3 d-flex flex-column" id={styles.contact}>
            <span>About us</span>
            <span>Partner With Us</span>
          </div>
          <div className="col-5 " id={styles.contact}>
            <span>Download OYO app for exciting offers</span>
          </div>
        </div>
        <div className="row" id={styles.FooterDesContainer}>
          <div className="col-12 p-0">
            <span className="ml-0" id={styles.FooterDesHeader}>
              OYO HOTELS
            </span>
          </div>
          <div className="col-12 d-flex p-0" id={styles.FooterHotelInfo}>
            <div className="col-2 d-flex flex-column justify-content-start p-0" id={styles.FooterSpan}>
              <span>Hotels in London</span>
              <span>Hotels in EastBourne</span>
              <span>Hotels in Belfast</span>
              <span>Hotels in Birmingham</span>
              <span>Hotels in Aberlour</span>
            </div>
            <div className="col-2 d-flex flex-column justify-content-start p-0" id={styles.FooterSpan}>
              <span>Hotels in Aberdeen</span>
              <span>Hotels in Liverpool</span>
              <span>Hotels in Newcastle</span>
              <span>Hotels in Bournemouth</span>
              <span>Hotels in Cannock</span>
            </div>
            <div className="col-2 d-flex flex-column justify-content-start p-0" id={styles.FooterSpan}>
              <span>Hotels in Luton</span>
              <span>Hotels in Barrow-In</span>
              <span>Hotels in St Helnes</span>
              <span>Hotels in Brighton</span>
              <span>Hotels in Durham</span>
            </div>
            <div className="col-2 d-flex flex-column justify-content-start p-0" id={styles.FooterSpan}>
              <span>Hotels in Peterhead</span>
              <span>Hotels in Peebles</span>
              <span>Hotels in Guide UK</span>
              <span>Hotels in Coventry</span>
              <span>Hotels in Gosport</span>
            </div>
            <div className="col-2 d-flex flex-column justify-content-start p-0" id={styles.FooterSpan}>
              <span>Hotels in Isle of Wight</span>
              <span>Hotels in Manchester</span>
              <span>Hotels in Leicester</span>
              <span>Hotels in Great Yarmouth</span>
              <span>Hotels in Hitchin</span>
            </div>
            <div className="col-2 d-flex flex-column justify-content-start p-0" id={styles.FooterSpan}>
              <span>Hotels in Derby</span>
              <span>Hotels in Cardiff</span>
              <span>Hotels in Edinburgh</span>
              <span>Hotels in Maidstone</span>
              <span>Hotels in Hythe</span>
            </div>
          </div>
        </div>
        <div className="row" id={styles.FooterDesContainer}>
          <div className="col-12 d-flex p-0">
            <div className="col-4 p-0" id={styles.FooterSocialMedia}>
              <span className="m-0">
                <svg>
                  <use xlinkHref="#facebook">
                    <svg id="facebook" viewBox="0 0 26 26">
                      <path d="M13 25.5C6.096 25.5.5 19.904.5 13S6.096.5 13 .5 25.5 6.096 25.5 13 19.904 25.5 13 25.5zm0-1c6.35 0 11.5-5.15 11.5-11.5S19.35 1.5 13 1.5 1.5 6.65 1.5 13 6.65 24.5 13 24.5z" fill-rule="nonzero"></path>
                      <path d="M14.867 12.49h-1.504V18h-2.28v-5.51H10v-1.937h1.084V9.3c0-.897.426-2.3 2.3-2.3l1.687.007v1.88h-1.224c-.2 0-.483.1-.483.528v1.14h1.703l-.2 1.934z"></path>
                    </svg>
                  </use>
                </svg>
              </span>
              <span>
                <svg>
                  <use xlinkHref="#instagram">
                    <svg id="instagram" viewBox="0 0 26 26">
                      <path d="M13 25.5C6.096 25.5.5 19.904.5 13S6.096.5 13 .5 25.5 6.096 25.5 13 19.904 25.5 13 25.5zm0-1c6.35 0 11.5-5.15 11.5-11.5S19.35 1.5 13 1.5 1.5 6.65 1.5 13 6.65 24.5 13 24.5z"></path>
                      <path d="M16.6 7.4H9.464c-1.14 0-2.065.926-2.065 2.065V16.6c0 1.138.926 2.064 2.065 2.064H16.6c1.138 0 2.064-.926 2.064-2.065V9.464c0-1.14-.926-2.065-2.065-2.065zm-3.568 9.34c-2.045 0-3.708-1.663-3.708-3.708s1.663-3.708 3.708-3.708 3.708 1.663 3.708 3.708-1.663 3.708-3.708 3.708zm3.827-6.65c-.485 0-.878-.393-.878-.877 0-.483.393-.877.877-.877.483 0 .877.394.877.877 0 .484-.394.878-.878.878z"></path>
                      <path d="M13.008 10.867c-1.18 0-2.14.96-2.14 2.14 0 1.18.96 2.142 2.14 2.142 1.18 0 2.14-.962 2.14-2.143 0-1.18-.96-2.14-2.14-2.14z"></path>
                    </svg>
                  </use>
                </svg>
              </span>
              <span>
                <svg>
                  <use xlinkHref="#linkedin">
                    <svg id="linkedin" viewBox="0 0 30 30">
                      <g id="Layer_1-2" data-name="Layer_1">
                        <circle fill="none" stroke="#fff" stroke-miterlimit="10" stroke-width="0.5px" cx="15" cy="15" r="14.63"></circle>
                        <path
                          fill="#fff"
                          d="M22.75,22h-3.3V15a1.51,1.51,0,0,0-.2-.88,1,1,0,0,0-.83-.31,1.73,1.73,0,0,0-1.78,1.21V22H13.17V10.66h3.47v.9a5.94,5.94,0,0,1,.92-.48,5.34,5.34,0,0,1,2.06-.41,3,3,0,0,1,2.46,1.26,5.29,5.29,0,0,1,.84,3.2V22Z"
                        ></path>
                        <path fill="#fff" d="M9.72,9.29A1.65,1.65,0,0,1,9.72,6h0a1.65,1.65,0,0,1,1.16.49,1.59,1.59,0,0,1,.48,1.15A1.64,1.64,0,0,1,9.72,9.29Z"></path>
                        <polygon fill="#fff" points="11.29 22 8.15 22 7.98 22 7.98 21.83 7.98 10.83 7.98 10.66 8.15 10.66 11.29 10.66 11.46 10.66 11.46 10.83 11.46 21.83 11.46 22 11.29 22"></polygon>
                      </g>
                    </svg>
                  </use>
                </svg>
              </span>
            </div>
            <div className="col-4"></div>
            <div className="col-4" id={styles.FooterCopyright}>
              2013-2020 © Enjoys Stays Private Limited
            </div>
          </div>
        </div>
      </div>
    );
  }
}
