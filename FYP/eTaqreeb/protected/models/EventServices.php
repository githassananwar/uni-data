<?php

/**
 * This is the model class for table "event_services".
 *
 * The followings are the available columns in table 'event_services':
 * @property integer $id
 * @property integer $vendor_service_id
 * @property integer $event_id
 * @property string $status
 *
 * The followings are the available model relations:
 * @property VendorServices $vendorService
 * @property Event $event
 */
class EventServices extends CActiveRecord
{
	/**
	 * @return string the associated database table name
	 */
	public function tableName()
	{
		return 'event_services';
	}

	/**
	 * @return array validation rules for model attributes.
	 */
	public function rules()
	{
		// NOTE: you should only define rules for those attributes that
		// will receive user inputs.
		return array(
			array('vendor_service_id, event_id, status', 'required'),
			array('vendor_service_id, event_id', 'numerical', 'integerOnly'=>true),
			array('status', 'length', 'max'=>50),
			// The following rule is used by search().
			// @todo Please remove those attributes that should not be searched.
			array('id, vendor_service_id, event_id, status', 'safe', 'on'=>'search'),
		);
	}

	/**
	 * @return array relational rules.
	 */
	public function relations()
	{
		// NOTE: you may need to adjust the relation name and the related
		// class name for the relations automatically generated below.
		return array(
			'vendorService' => array(self::BELONGS_TO, 'VendorServices', 'vendor_service_id'),
			'event' => array(self::BELONGS_TO, 'Event', 'event_id'),
		);
	}

	/**
	 * @return array customized attribute labels (name=>label)
	 */
	public function attributeLabels()
	{
		return array(
			'id' => 'ID',
			'vendor_service_id' => 'Vendor Service',
			'event_id' => 'Event',
			'status' => 'Status',
		);
	}

	/**
	 * Retrieves a list of models based on the current search/filter conditions.
	 *
	 * Typical usecase:
	 * - Initialize the model fields with values from filter form.
	 * - Execute this method to get CActiveDataProvider instance which will filter
	 * models according to data in model fields.
	 * - Pass data provider to CGridView, CListView or any similar widget.
	 *
	 * @return CActiveDataProvider the data provider that can return the models
	 * based on the search/filter conditions.
	 */
	public function search()
	{
		// @todo Please modify the following code to remove attributes that should not be searched.

		$criteria=new CDbCriteria;

		$criteria->compare('id',$this->id);
		$criteria->compare('vendor_service_id',$this->vendor_service_id);
		$criteria->compare('event_id',$this->event_id);
		$criteria->compare('status',$this->status,true);

		return new CActiveDataProvider($this, array(
			'criteria'=>$criteria,
		));
	}

	/**
	 * Returns the static model of the specified AR class.
	 * Please note that you should have this exact method in all your CActiveRecord descendants!
	 * @param string $className active record class name.
	 * @return EventServices the static model class
	 */
	public static function model($className=__CLASS__)
	{
		return parent::model($className);
	}
}
