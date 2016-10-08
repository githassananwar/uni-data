<?php

use backendless\Backendless;
//use backendless\model\BackendlessUser;
use eTaqreeb\customerVariables;
include $_SERVER['DOCUMENT_ROOT']."/eTaqreeb/Vendor/backendless/autoload.php";
include $_SERVER['DOCUMENT_ROOT'].'/eTaqreeb/customerVariables.php';

class CustomerController extends Controller
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
		// 	array('allow',  // allow all users to perform 'index' and 'view' actions
		// 		'actions'=>array('index','view'),
		// 		'users'=>array('*'),
		// 	),
		// 	array('allow', // allow authenticated user to perform 'create' and 'update' actions
		// 		'actions'=>array('create','update'),
		// 		'users'=>array('@'),
		// 	),
		// 	array('allow', // allow admin user to perform 'admin' and 'delete' actions
		// 		'actions'=>array('admin','delete'),
		// 		'users'=>array('admin'),
		// 	),
		// 	array('deny',  // deny all users
		// 		'users'=>array('*'),
		// 	),
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
		$model=new Customer;

		// Uncomment the following line if AJAX validation is needed
		// $this->performAjaxValidation($model);

		if(isset($_POST['Customer']))
		{
			$model->attributes=$_POST['Customer'];
			if($model->save())
				$this->redirect(array('view','id'=>$model->id));
		}

		$this->render('create',array(
			'model'=>$model,
		));
	}

	public function actionSignup()
	{
	
	
		$model = new Customer;
		if(isset($_POST['Customer']) && $_POST['Customer'])
		{
			$model->attributes = $_POST['Customer'];
			if($model->save())
			{
				
				
 
Backendless::initApp('A9F16720-F3AC-43F0-FFC4-99CDEAECBF00', '7FD0DC71-7ECC-95D3-FF9D-B24B36095C00', 'v1');
 
$user = new customerVariables();
$user->setNam( $model->name );
$user->setUserr( $model->username );
$user->setMaill( $model->email );
$user->setPas( $model->password );
$user->setCont( $model->contact );
 
Backendless::$Persistence->save( $user);

				$this->redirect(array('site/index'));
			}
			
		}
		$this->render('signupCustomer',array(
				'model'=> $model,
			));
	}

	public function actionLogin()
	{

		 $username = $_POST['name'];
		 $password = $_POST['password'];

		 $condition = "username=:user AND password=:pass";
		 $params = array(

		 		':user'=>$username,
		 		':pass'=>$password,

		 	);

		 $value = Customer::model()->find($condition,$params);

		 if($value)
		 {
		 	$_SESSION['login_user'] = $username;
		 	$_SESSION['user-type'] = 'customer';
		 	$_SESSION['user-id'] = $value->id;

		 	print "login";
		 	
		 }
		 
	}

	public function actionLogout()
	{
		unset($_SESSION["login_user"]);
		unset($_SESSION["user-type"]);
		unset($_SESSION["user-id"]);
		unset($_SESSION['current_event']); 
		unset($_SESSION['current_eventid'] );
		 $this->redirect(array('site/index'));
	}

	/**
	 * Updates a particular model.
	 * If update is successful, the browser will be redirected to the 'view' page.
	 * @param integer $id the ID of the model to be updated
	 */
	public function actionUpdate($id)
	{
		$model=$this->loadModel($id);

		// Uncomment the following line if AJAX validation is needed
		// $this->performAjaxValidation($model);

		if(isset($_SESSION["login_admin"]) && isset($_POST['Customer']))
		{
			$model->attributes=$_POST['Customer'];
			if($model->save())
				$this->redirect('?r=admin/manageCustomers');
		}


		if(isset($_POST['Customer']))
		{
			$model->attributes=$_POST['Customer'];
			if($model->save())
				$this->redirect(array('view','id'=>$model->id));
		}
		
		$this->render('update',array(
			'model'=>$model,
		));
	}

	/**
	 * Deletes a particular model.
	 * If deletion is successful, the browser will be redirected to the 'admin' page.
	 * @param integer $id the ID of the model to be deleted
	 */
	public function beforedelete($id)
	{
		$events=Event::model()->findAllByAttributes(array('customer_id'=>$id));
		if($events)
		{
			foreach($events as $event)
			{
				
				EventServices::model()->deleteAll('event_id=:eid',array(':eid'=>$event->id));

			}
			Event::model()->deleteAll('customer_id=:cid',array(':cid'=>$id));

			Message::model()->deleteAll('customer_id=:cid',array(':cid'=>$id));
		}
		
	}

	/**
	 * Deletes a particular model.
	 * If deletion is successful, the browser will be redirected to the 'admin' page.
	 * @param integer $id the ID of the model to be deleted
	 */
	public function actionDeleteCustomer($id)
	{
		if(isset($_SESSION["login_admin"]))
		{
			$this->beforedelete($id);
        	$this->loadModel($id)->delete();
			$this->redirect('?r=admin/manageCustomers');
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
		$dataProvider=new CActiveDataProvider('Customer');
		$this->render('index',array(
			'dataProvider'=>$dataProvider,
		));
	}

	/**
	 * Manages all models.
	 */
	public function actionAdmin()
	{
		$model=new Customer('search');
		$model->unsetAttributes();  // clear any default values
		if(isset($_GET['Customer']))
			$model->attributes=$_GET['Customer'];

		$this->render('admin',array(
			'model'=>$model,
		));
	}

	/**
	 * Returns the data model based on the primary key given in the GET variable.
	 * If the data model is not found, an HTTP exception will be raised.
	 * @param integer $id the ID of the model to be loaded
	 * @return Customer the loaded model
	 * @throws CHttpException
	 */
	public function loadModel($id)
	{
		$model=Customer::model()->findByPk($id);
		if($model===null)
			throw new CHttpException(404,'The requested page does not exist.');
		return $model;
	}

	/**
	 * Performs the AJAX validation.
	 * @param Customer $model the model to be validated
	 */
	protected function performAjaxValidation($model)
	{
		if(isset($_POST['ajax']) && $_POST['ajax']==='customer-form')
		{
			echo CActiveForm::validate($model);
			Yii::app()->end();
		}
	}
}
