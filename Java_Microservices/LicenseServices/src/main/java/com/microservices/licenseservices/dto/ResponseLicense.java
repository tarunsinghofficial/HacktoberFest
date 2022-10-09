package com.microservices.licenseservices.dto;

import com.microservices.licenseservices.model.License;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class ResponseLicense {
    private String response;
    private String messages;
    private License data;
}
