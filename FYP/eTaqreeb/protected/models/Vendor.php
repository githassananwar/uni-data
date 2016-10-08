<?php

/**
 * This is the model class for table "vendor".
 *
 * The followings are the available columns in table 'vendor':
 * @property integer $id
 * @property string $name
 * @property string $companyname
 * @property string $description
 * @property string $address
 * @property string $contact1
 * @property string $contact2
 * @property string $email
 * @property string $username
 * @property string $password
 * @property string $availability
 * @property string $image
 *
 * The followings are the available model relations:
 * @property Rating[] $ratings
 * @property VendorServices[] $vendorServices
 */
class Vendor extends CActiveRecord
{
	/**
	 * @return string the associated database table name
	 */
	public function tableName()
	{
		return 'vendor';
	}

	/**
	 * @return array validation rules for model attributes.
	 */
	public function rules()
	{
		// NOTE: you should only define rules for those attributes that
		// will receive user inputs.
		return array(
			array('name, companyname, address, contact1, contact2, email, username, password, availability, image', 'required'),
			array('name, companyname', 'length', 'max'=>200),
			array('address', 'length', 'max'=>500),
			array('image','file','types'=>'jpg, gif, png','allowEmpty'=>true, 'safe' => false),
			array('contact1, contact2, email, username, password, image', 'length', 'max'=>100),
			array('availability', 'length', 'max'=>10),
			array('description', 'safe'),
			// The following rule is used by search().
			// @todo Please remove those attributes that should not be searched.
			array('id, name, companyname, description, address, contact1, contact2, email, username, password, availability, image', 'safe', 'on'=>'search'),
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
			'ratings' => array(self::HAS_MANY, 'Rating', 'vendor_id'),
			'vendorServices' => array(self::HAS_MANY, 'VendorServices', 'vendor_id'),
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
			'companyname' => 'Companyname',
			'description' => 'Description',
			'address' => 'Address',
			'contact1' => 'Contact1',
			'contact2' => 'Contact2',
			'email' => 'Email',
			'username' => 'Username',
			'password' => 'Password',
			'availability' => 'Availability',
			'image' => 'Image',
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
		$criteria->compare('companyname',$this->companyname,true);
		$criteria->compare('description',$this->description,true);
		$criteria->compare('address',$this->address,true);
		$criteria->compare('contact1',$this->contact1,true);
		$criteria->compare('contact2',$this->contact2,true);
		$criteria->compare('email',$this->email,true);
		$criteria->compare('username',$this->username,true);
		$criteria->compare('password',$this->password,true);
		$criteria->compare('availability',$this->availability,true);
		$criteria->compare('image',$this->image,true);

		return new CActiveDataProvider($this, array(
			'criteria'=>$criteria,
		));
	}

	/**
	 * Returns the static model of the specified AR class.
	 * Please note that you should have this exact method in all your CActiveRecord descendants!
	 * @param string $className active record class name.
	 * @return Vendor the static model class
	 */
	public static function model($className=__CLASS__)
	{
		return parent::model($className);
	}
}
