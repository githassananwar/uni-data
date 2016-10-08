package com.example.google.etakreeb;

/**
 * Created by Google on 5/20/2016.
 */
public class createEventVariables {
    String event;
    String dat;
    String tBudget;
    String typ;
    String sh;
    String objectId;
    String cObjectId;

    public String getcObjectId() {
        return cObjectId;
    }

    public void setcObjectId(String cObjectId) {
        this.cObjectId = cObjectId;
    }



    public String getObjectId() {
        return objectId;
    }

    public void setObjectId(String objectId) {
        this.objectId = objectId;
    }



    public String getEvent() {
        return event;
    }

    public void setEvent(String event) {
        this.event = event;
    }

    public String getDat() {
        return dat;
    }

    public void setDat(String date) {
        dat = date;
    }



    public String gettBudget() {
        return tBudget;
    }

    public void settBudget(String tBudget) {
        this.tBudget = tBudget;
    }

    public String getTyp() {
        return typ;
    }

    public void setTyp(String typ) {
        this.typ = typ;
    }

    public String getSh() {
        return sh;
    }

    public void setSh(String shift) {
        this.sh = shift;
    }
}
