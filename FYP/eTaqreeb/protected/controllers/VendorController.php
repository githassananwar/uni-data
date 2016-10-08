<?php

use backendless\Backendless;
//use backendless\model\BackendlessUser;
use eTaqreeb\vendorVariables;
include $_SERVER['DOCUMENT_ROOT']."eTaqreeb/Vendor/backendless/autoload.php";
include $_SERVER['DOCUMENT_ROOT'].'eTaqreeb/vendorVariables.php';

class VendorController extends Controller
{
	/**
	 * @var string the default layout for the views. Defaults to '//layouts/column2', meaning
	 * using two-column layout. See 'protected/views/layouts/column2.php'.
	 */
	public $layout='//layouts/column2';

	/**
	 * @return array action filters
	 */
	public function filters()
	{
		return array(
			'accessControl', // perform access control for CRUD operations
			'postOnly + delete', // we only allow deletion via POST request
		);
	}

	/**
	 * Specifies the access control rules.
	 * This method is used by the 'accessControl' filter.
	 * @return array access control rules
	 */
	public function accessRules()
	{
		return array(
			// array('allow',  // allow all users to perform 'index' and 'view' actions
			// 	'actions'=>array('index','view'),
			// 	'users'=>array('*'),
			// ),
			// array('allow', // allow authenticated user to perform 'create' and 'update' actions
			// 	'actions'=>array('create','update'),
			// 	'users'=>array('@'),
			// ),
			// array('allow', // allow admin user to perform 'admin' and 'delete' actions
			// 	'actions'=>array('admin','delete'),
			// 	'users'=>array('admin'),
			// ),
			// array('deny',  // deny all users
			// 	'users'=>array('*'),
			// ),
		);
	}

	/**
	 * Displays a particular model.
	 * @param integer $id the ID of the model to be displayed
	 */
	public function actionView($id)
	{
		$this->render('view',array(
			'model'=>$this->loadModel($id),
		));
	}

	/**
	 * Creates a new model.
	 * If creation is successful, the browser will be redirected to the 'view' page.
	 */
	public function actionCreate()
	{
		$model=new Vendor;

		// Uncomment the following line if AJAX validation is needed
		// $this->performAjaxValidation($model);

		if(isset($_POST['Vendor']))
		{
			$model->attributes=$_POST['Vendor'];
			if($model->save())
				$this->redirect(array('view','id'=>$model->id));
		}

		$this->render('create',array(
			'model'=>$model,
		));
	}

	/**
	 * Updates a particular model.
	 * If update is successful, the browser will be redirected to the 'view' page.
	 * @param integer $id the ID of the model to be updated
	 */
	public function actionUpdate($id)
	{
		$model=$this->loadModel($id);

		if(isset($_SESSION["login_admin"]) && isset($_POST['Vendor']))
		{
			
			$model->attributes=$_POST['Vendor'];
			if($model->save()){
				$this->redirect('?r=admin/manageVendors');	
				
			}				
		}
		if(isset($_POST['Vendor']))
		{
			$model->attributes=$_POST['Vendor'];
			if($model->save()){
				$this->redirect(array('view','id'=>$model->id));
				
			}		
		}

		$this->render('update',array(
			'model'=>$model,
		));


	}

public function actionSignup()
{
		$model = new Vendor;
		$modelRating=new Rating;
		if(isset($_POST['Vendor']))
		{

			$model->attributes = $_POST['Vendor'];
			$model->image = CUploadedFile::getInstance($model,'image');

			if($model->save())
			{
				$ext = explode(".", $model->image->name);
				$model->image->saveAs('C:\wamp\www\eTaqreeb\images\vendor/'.'vendor'.$model->id.'.'.end($ext)); 
				
				
				$modelRating->vendor_id=$model->id;
			$modelRating->noOfRatings=0;
			$modelRating->rating=0;
			$modelRating->save();
				
 				Backendless::initApp('A9F16720-F3AC-43F0-FFC4-99CDEAECBF00', '7FD0DC71-7ECC-95D3-FF9D-B24B36095C00', 'v1');
 
 $user = new vendorVariables();
 $user->setvName( $model->name );
 $user->setcName( $model->companyname );
 $user->setcAddress( $model->address );
 $user->setLandline( $model->contact1 );
 $user->setMobileNum( $model->contact2 );
 $user->setEmaill( $model->email );
 $user->setUserr( $model->username );
 $user->setPas( $model->password );
 
 Backendless::$Persistence->save( $user);
			
 						$this->redirect(array('site/index'));	
					
 			}
		}

	
		$this->render('signupVendor',array(
				'model'=> $model,
			));

	}


	public function beforedelete($id)
	{
		$services=VendorServices::model()->findAllByAttributes(array('vendor_id'=>$id));
		if($services)
		{
			foreach($services as $service)
			{
				
				EventServices::model()->deleteAll('vendor_service_id=:sid',array(':sid'=>$service->id));

			}
			VendorServices::model()->deleteAll('vendor_id=:vid',array(':vid'=>$id));


		}

		Rating::model()->deleteAll('vendor_id=:vid',array(':vid'=>$id));

		Message::model()->deleteAll('vendor_id=:vid',array(':vid'=>$id));
		
	}


	/**
	 * Deletes a particular model.
	 * If deletion is successful, the browser will be redirected to the 'admin' page.
	 * @param integer $id the ID of the model to be deleted
	 */
	public function actionDeleteVendor($id)
	{
		if(isset($_SESSION["login_admin"]))
		{
			$this->beforedelete($id);
        	$this->loadModel($id)->delete();
			$this->redirect('?r=admin/manageVendors');
		}
		else
		{
			$this->redirect('index.php');
		}	
	}

	/**
	 * Lists all models.
	 */
	public function actionIndex()
	{
		$dataProvider=new CActiveDataProvider('Vendor');
		$this->render('index',array(
			'dataProvider'=>$dataProvider,
		));
	}

	

	public function actionLogin()
	{
		//$session = Yii::$app->session;
		 $username = $_POST['name'];
		 $password = $_POST['password'];

		 $condition = "username=:user AND password=:pass";
		 $params = array(

		 		':user'=>$username,
		 		':pass'=>$password,

		 	);

		 $value = Vendor::model()->find($condition,$params);

		 if($value)
		 {
		 	$_SESSION['login_user'] = $username;
		 	$_SESSION['user-type'] = 'vendor';
		 	$_SESSION['user-id'] = $value->id;

		 	print "login";
		 	
		 }
		 
	}

	public function actionLogout()
	{
		unset($_SESSION["login_user"]);
		unset($_SESSION["user-type"]);
		 unset($_SESSION["user-id"]);
		 $this->redirect(array('site/index'));
	}



	/**
	 * Manages all models.
	 */
	public function actionAdmin()
	{
		$model=new Vendor('search');
		$model->unsetAttributes();  // clear any default values
		if(isset($_GET['Vendor']))
			$model->attributes=$_GET['Vendor'];

		$this->render('admin',array(
			'model'=>$model,
		));
	}

	/**
	 * Returns the data model based on the primary key given in the GET variable.
	 * If the data model is not found, an HTTP exception will be raised.
	 * @param integer $id the ID of the model to be loaded
	 * @return Vendor the loaded model
	 * @throws CHttpException
	 */
	public function loadModel($id)
	{
		$model=Vendor::model()->findByPk($id);
		if($model===null)
			throw new CHttpException(404,'The requested page does not exist.');
		return $model;
	}

	/**
	 * Performs the AJAX validation.
	 * @param Vendor $model the model to be validated
	 */
	protected function performAjaxValidation($model)
	{
		if(isset($_POST['ajax']) && $_POST['ajax']==='vendor-form')
		{
			echo CActiveForm::validate($model);
			Yii::app()->end();
		}
	}
}
