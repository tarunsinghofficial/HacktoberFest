import React from "react";
import Lottie from "react-lottie";

export default function LottieAnimation({ lotti, width, height }) {
  const lottieRef = React.useRef(null);
  const handleClickToPause = () => lottieRef?.current?.handleClickToPause?.();

  const defaultOptions = {
    loop: true,
    autoplay: false,
    animationData: lotti,
    rendererSettings: {
      preserveAspectRatio: "xMidYMid slice",
    },
  };

  return (
    <div onMouseEnter={handleClickToPause} onMouseLeave={handleClickToPause}>
      <Lottie
        options={defaultOptions}
        height={height}
        width={width}
        ref={lottieRef}
      />
    </div>
  );
}
