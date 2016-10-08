<?php

/**
 * This is the model class for table "event".
 *
 * The followings are the available columns in table 'event':
 * @property integer $id
 * @property string $name
 * @property string $type
 * @property string $date
 * @property string $shift
 * @property integer $customer_id
 * @property integer $budget
 * @property integer $numOfGuests
 * @property integer $current_budget
 *
 * The followings are the available model relations:
 * @property Customer $customer
 * @property EventServices[] $eventServices
 */
class Event extends CActiveRecord
{
	/**
	 * @return string the associated database table name
	 */
	public function tableName()
	{
		return 'event';
	}

	/**
	 * @return array validation rules for model attributes.
	 */
	public function rules()
	{
		// NOTE: you should only define rules for those attributes that
		// will receive user inputs.
		return array(
			array('name, type, date, shift, customer_id, budget, numOfGuests, current_budget', 'required'),
			array('customer_id, budget, numOfGuests, current_budget', 'numerical', 'integerOnly'=>true),
			array('name, type', 'length', 'max'=>200),
			array('date', 'length', 'max'=>100),
			array('shift', 'length', 'max'=>50),
			// The following rule is used by search().
			// @todo Please remove those attributes that should not be searched.
			array('id, name, type, date, shift, customer_id, budget, numOfGuests, current_budget', 'safe', 'on'=>'search'),
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
			'customer' => array(self::BELONGS_TO, 'Customer', 'customer_id'),
			'eventServices' => array(self::HAS_MANY, 'EventServices', 'event_id'),
		);
	}

	/**
	 * @return array customized attribute labels (name=>label)
	 */
	public function attributeLabels()
	{
		return array(
			'id' => 'ID',
			'name' => 'Name',
			'type' => 'Type',
			'date' => 'Date',
			'shift' => 'Shift',
			'customer_id' => 'Customer',
			'budget' => 'Budget',
			'numOfGuests' => 'Num Of Guests',
			'current_budget' => 'Current Budget',
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
		$criteria->compare('name',$this->name,true);
		$criteria->compare('type',$this->type,true);
		$criteria->compare('date',$this->date,true);
		$criteria->compare('shift',$this->shift,true);
		$criteria->compare('customer_id',$this->customer_id);
		$criteria->compare('budget',$this->budget);
		$criteria->compare('numOfGuests',$this->numOfGuests);
		$criteria->compare('current_budget',$this->current_budget);

		return new CActiveDataProvider($this, array(
			'criteria'=>$criteria,
		));
	}

	/**
	 * Returns the static model of the specified AR class.
	 * Please note that you should have this exact method in all your CActiveRecord descendants!
	 * @param string $className active record class name.
	 * @return Event the static model class
	 */
	public static function model($className=__CLASS__)
	{
		return parent::model($className);
	}
}
