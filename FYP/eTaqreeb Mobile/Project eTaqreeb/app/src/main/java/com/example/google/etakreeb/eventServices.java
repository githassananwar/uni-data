package com.example.google.etakreeb;

import javax.net.ssl.SSLContext;

/**
 * Created by Google on 5/29/2016.
 */
public class eventServices {
    String  status;
    String eobjectId;
    String vSObjectId;
    String eventName;
    String vName;
    String objectId;

    public String getEventName() {
        return eventName;
    }

    public void setEventName(String eventName) {
        this.eventName = eventName;
    }

    public String getvName() {
        return vName;
    }

    public void setvName(String vName) {
        this.vName = vName;
    }

    String vObjectId;


    public String getvObjectId() {
        return vObjectId;
    }

    public void setvObjectId(String vObjectId) {
        this.vObjectId = vObjectId;
    }

    public String getEobjectId() {
        return eobjectId;
    }

    public void setEobjectId(String eobjectId) {
        this.eobjectId = eobjectId;
    }

    public String getvSObjectId() {
        return vSObjectId;
    }

    public void setvSObjectId(String vSObjectId) {
        this.vSObjectId = vSObjectId;
    }

    public String getObjectId() {
        return objectId;
    }

    public void setObjectId(String objectId) {
        this.objectId = objectId;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }
}
