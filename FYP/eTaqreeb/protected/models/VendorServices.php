<?php

/**
 * This is the model class for table "vendor_services".
 *
 * The followings are the available columns in table 'vendor_services':
 * @property integer $id
 * @property string $name
 * @property double $price
 * @property string $type
 * @property integer $vendor_id
 * @property string $pricemode
 * @property string $simage
 *
 * The followings are the available model relations:
 * @property EventServices[] $eventServices
 * @property Vendor $vendor
 */
class VendorServices extends CActiveRecord
{
	/**
	 * @return string the associated database table name
	 */
	public function tableName()
	{
		return 'vendor_services';
	}

	/**
	 * @return array validation rules for model attributes.
	 */
	public function rules()
	{
		// NOTE: you should only define rules for those attributes that
		// will receive user inputs.
		return array(
			array('name, price, type, vendor_id, pricemode, simage', 'required'),
			array('vendor_id', 'numerical', 'integerOnly'=>true),
			array('price', 'numerical'),
			array('name, type', 'length', 'max'=>200),
			array('pricemode, simage', 'length', 'max'=>100),
			array('simage','file','types'=>'jpg, gif, png','allowEmpty'=>true, 'safe' => false),
			// The following rule is used by search().
			// @todo Please remove those attributes that should not be searched.
			array('id, name, price, type, vendor_id, pricemode, simage', 'safe', 'on'=>'search'),
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
			'eventServices' => array(self::HAS_MANY, 'EventServices', 'vendor_service_id'),
			'vendor' => array(self::BELONGS_TO, 'Vendor', 'vendor_id'),
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
			'price' => 'Price',
			'type' => 'Type',
			'vendor_id' => 'Vendor',
			'pricemode' => 'Pricemode',
			'simage' => 'Simage',
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
		$criteria->compare('price',$this->price);
		$criteria->compare('type',$this->type,true);
		$criteria->compare('vendor_id',$this->vendor_id);
		$criteria->compare('pricemode',$this->pricemode,true);
		$criteria->compare('simage',$this->simage,true);

		return new CActiveDataProvider($this, array(
			'criteria'=>$criteria,
		));
	}

	/**
	 * Returns the static model of the specified AR class.
	 * Please note that you should have this exact method in all your CActiveRecord descendants!
	 * @param string $className active record class name.
	 * @return VendorServices the static model class
	 */
	public static function model($className=__CLASS__)
	{
		return parent::model($className);
	}
}
