package com.microservices.licenseservices.repository;

import com.microservices.licenseservices.model.License;

public interface CustomLicenseRepository {
    License partialUpdate(final String licenseKey, final String fieldName, Object fieldValue);

}
