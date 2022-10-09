package com.microservices.licenseservices.controller;

import com.microservices.licenseservices.dao.LicenseDao;
import com.microservices.licenseservices.dto.ResponseLicense;
import com.microservices.licenseservices.model.License;
import com.microservices.licenseservices.repository.LicenseRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.util.StringUtils;
import org.springframework.web.bind.annotation.*;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.List;
import java.util.Objects;

@RestController
@RequestMapping("/license")
public class LicenseController {

    @Autowired
    private LicenseRepository licenseRepository;

    @Autowired
    private LicenseDao licenseDao;

    @PostMapping
    public ResponseEntity<ResponseLicense> save(@RequestBody License license){
        License key = licenseDao.save(license);
        ResponseLicense responseLicense = new ResponseLicense();
        HttpHeaders header = new HttpHeaders();
        responseLicense.setResponse("success");
        responseLicense.setMessages("License Key successfully create");
        responseLicense.setData(key);
        return ResponseEntity.status(HttpStatus.OK).headers(header).body(responseLicense);
    }

    @GetMapping
    public List<License> findAll(){
        return licenseDao.findAll();
    }

    @GetMapping("/{licenseKey}")
    public ResponseEntity<ResponseLicense> findByKey(@PathVariable("licenseKey") String licenseKey){
        License key = licenseRepository.findLicensesByLicenseKey(licenseKey);
        ResponseLicense responseLicense = new ResponseLicense();
        if(key != null){
            HttpHeaders header = new HttpHeaders();
            responseLicense.setResponse("success");
            responseLicense.setMessages("Data Found");
            responseLicense.setData(key);
            return ResponseEntity.status(HttpStatus.OK).headers(header).body(responseLicense);
        }else{
            HttpHeaders header = new HttpHeaders();
            responseLicense.setResponse("failed");
            responseLicense.setMessages("Data Not Found");
            return ResponseEntity.status(HttpStatus.NOT_FOUND).headers(header).body(responseLicense);
        }
    }

    @PatchMapping("/{licenseKey}")
    public ResponseEntity<ResponseLicense> partialUpdateLicenseKey(@PathVariable("licenseKey") final String licenseKey,
                                        @RequestBody final License license) throws Exception {
        HttpHeaders header = new HttpHeaders();
        ResponseLicense responseLicense = new ResponseLicense();
        responseLicense.setResponse("success");
        responseLicense.setMessages("Data Update");
        for (final Field field : License.class.getDeclaredFields()){
            final String fieldName = field.getName();

            if (fieldName.equals("licenseKey")){
                continue;
            }

            final Method getter = License.class.getDeclaredMethod("get"+
                    StringUtils.capitalize(fieldName));
            final Object fieldValue = getter.invoke(license);
            if (Objects.nonNull(fieldValue)){
                License key = licenseRepository.partialUpdate(licenseKey, fieldName, fieldValue);
                responseLicense.setData(key);
            }
        }
        return ResponseEntity.status(HttpStatus.OK).headers(header).body(responseLicense);
    }


    @DeleteMapping("/{licenseKey}")
    public ResponseEntity<ResponseLicense> delete(@PathVariable("licenseKey") String licenseKey){
        License key = licenseDao.delete(licenseKey);
        ResponseLicense responseLicense = new ResponseLicense();
        HttpHeaders header = new HttpHeaders();
        responseLicense.setResponse("success");
        responseLicense.setMessages("Data Deleted");
        responseLicense.setData(key);
        return ResponseEntity.status(HttpStatus.OK).headers(header).body(responseLicense);
    }
}
