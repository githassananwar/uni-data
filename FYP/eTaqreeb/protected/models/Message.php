<?php

/**
 * This is the model class for table "eTaqreeb.Message".
 *
 * The followings are the available columns in table 'eTaqreeb.Message':
 * @property integer $id
 * @property integer $customer_id
 * @property integer $vendor_id
 * @property integer $sent_by
 * @property string $body
 * @property string $dateTimeMeta
 */
class Message extends CActiveRecord
{
	/**
	 * @return string the associated database table name
	 */
	public function tableName()
	{
		return 'eTaqreeb.Message';
	}

	/**
	 * @return array validation rules for model attributes.
	 */
	public function rules()
	{
		// NOTE: you should only define rules for those attributes that
		// will receive user inputs.
		return array(
			array('customer_id, vendor_id, sent_by, body, dateTimeMeta', 'required'),
			array('customer_id, vendor_id, sent_by', 'numerical', 'integerOnly'=>true),
			array('body', 'length', 'max'=>1000),
			// The following rule is used by search().
			// @todo Please remove those attributes that should not be searched.
			array('id, customer_id, vendor_id, sent_by, body, dateTimeMeta', 'safe', 'on'=>'search'),
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
		);
	}

	/**
	 * @return array customized attribute labels (name=>label)
	 */
	public function attributeLabels()
	{
		return array(
			'id' => 'ID',
			'customer_id' => 'Customer',
			'vendor_id' => 'Vendor',
			'sent_by' => 'Sent By',
			'body' => 'Body',
			'dateTimeMeta' => 'Date Time Meta',
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
		$criteria->compare('customer_id',$this->customer_id);
		$criteria->compare('vendor_id',$this->vendor_id);
		$criteria->compare('sent_by',$this->sent_by);
		$criteria->compare('body',$this->body,true);
		$criteria->compare('dateTimeMeta',$this->dateTimeMeta,true);

		return new CActiveDataProvider($this, array(
			'criteria'=>$criteria,
		));
	}

	/**
	 * Returns the static model of the specified AR class.
	 * Please note that you should have this exact method in all your CActiveRecord descendants!
	 * @param string $className active record class name.
	 * @return Message the static model class
	 */
	public static function model($className=__CLASS__)
	{
		return parent::model($className);
	}
}
