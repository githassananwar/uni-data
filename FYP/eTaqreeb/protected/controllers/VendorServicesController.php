<?php

class VendorServicesController extends Controller
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
			/*array('allow',  // allow all users to perform 'index' and 'view' actions
				'actions'=>array('index','view'),
				'users'=>array('*'),
			),
			array('allow', // allow authenticated user to perform 'create' and 'update' actions
				'actions'=>array('create','update'),
				'users'=>array('@'),
			),
			array('allow', // allow admin user to perform 'admin' and 'delete' actions
				'actions'=>array('admin','delete'),
				'users'=>array('admin'),
			),
			array('deny',  // deny all users
				'users'=>array('*'),
			),
			*/
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

	public function actionBook($id)
	{
		if( isset($_SESSION['current_event']) )
		{
			$eventService=new EventServices;
			$eventService->vendor_service_id=$id;

			
			$event=Event::model()->findByAttributes(array('id'=>$_SESSION['current_eventid']));
			$service=VendorServices::model()->findByAttributes(array('id'=>$id));
			
			if($service->pricemode=='Per Head')
			{
				$event->current_budget=$event->current_budget+( $event->numOfGuests*$service->price );
			}
			else
			{
				$event->current_budget=$event->current_budget+$service->price ;
			}
			
			$eventService->event_id=$_SESSION['current_eventid'];
			$eventService->status="Not confirm";
			if($eventService->save() && $event->save())
			$this->redirect(array('event/view&id='.$_SESSION['current_eventid']));
		}
		else
		{
			Yii::app()->user->setFlash('error','Error! Select Your Event');
			$this->redirect(array('site/vendorservices'));
		}

	}



	public function actionaddService()
	{
		if(isset($_SESSION["login_user"]) && !strcmp($_SESSION['user-type'],"vendor") )
		{

			$model = new VendorServices;
			if(isset($_POST['VendorServices']))
			{
				$model->attributes = $_POST['VendorServices'];
				$model->vendor_id = $_SESSION['user-id'];
				$model->simage = CUploadedFile::getInstance($model,'simage');
				
				if($model->save())
				{
					$ext = explode(".", $model->simage);
					$model->simage->saveAs('C:\wamp\www\eTaqreeb\images\services/'.'service'.$model->id.'.'.end($ext)); 
					$this->redirect(array('vendorservices/manageservices'));		

				}
				
			}
			$this->render('addService',array(
					'model'=> $model,
				));
		}
		
		else
		{
			$this->redirect(array('site/index'));
		}


	}

	public function actionmanageServices()
	{
		
		$this->render('manageservices');
	}


	/**
	 * Creates a new model.
	 * If creation is successful, the browser will be redirected to the 'view' page.
	 */
	public function actionCreate()
	{
		$model=new VendorServices;

		// Uncomment the following line if AJAX validation is needed
		// $this->performAjaxValidation($model);

		if(isset($_POST['VendorServices']))
		{
			$model->attributes=$_POST['VendorServices'];
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

		// Uncomment the following line if AJAX validation is needed
		// $this->performAjaxValidation($model);
		if(isset($_SESSION["login_admin"]) && isset($_POST['VendorServices']))
		{
			$model->attributes=$_POST['VendorServices'];
			if($model->save())
				$this->redirect('?r=admin/manageVendorServices');
		}
		if(isset($_POST['VendorServices']))
		{
			$model->attributes=$_POST['VendorServices'];
			if($model->save())
				$this->redirect(array('view','id'=>$model->id));
		}

		$this->render('update',array(
			'model'=>$model,
		));
	}

	/**
	 * Lists all models.
	 */
	public function actionIndex()
	{
		$dataProvider=new CActiveDataProvider('VendorServices');
		$this->render('index',array(
			'dataProvider'=>$dataProvider,
		));
	}

	/**
	 * Manages all models.
	 */
	public function actionAdmin()
	{
		$model=new VendorServices('search');
		$model->unsetAttributes();  // clear any default values
		if(isset($_GET['VendorServices']))
			$model->attributes=$_GET['VendorServices'];

		$this->render('admin',array(
			'model'=>$model,
		));
	}


	public function beforedelete($id)
	{
		
		EventServices::model()->deleteAll('vendor_service_id=:vid',array(':vid'=>$id));

	}


	/**
	 * Deletes a particular model.
	 * If deletion is successful, the browser will be redirected to the 'admin' page.
	 * @param integer $id the ID of the model to be deleted
	 */
	public function actionDeleteVendorService($id)
	{
		if(isset($_SESSION["login_admin"]) )
		{
			$this->beforedelete($id);
        	$this->loadModel($id)->delete();
			$this->redirect('?r=admin/manageVendorServices');
		}
		else if( (isset($_SESSION['user-type']) && !strcmp($_SESSION['user-type'],"vendor")) )
		{
			$this->beforedelete($id);
        	$this->loadModel($id)->delete();
			$this->redirect('?r=vendorservices/manageServices');
		}
		else
		{
			$this->redirect('index.php');
		}	
	}

	/**
	 * Returns the data model based on the primary key given in the GET variable.
	 * If the data model is not found, an HTTP exception will be raised.
	 * @param integer $id the ID of the model to be loaded
	 * @return VendorServices the loaded model
	 * @throws CHttpException
	 */
	public function loadModel($id)
	{
		$model=VendorServices::model()->findByPk($id);
		if($model===null)
			throw new CHttpException(404,'The requested page does not exist.');

		return $model;

	}

	/**
	 * Performs the AJAX validation.
	 * @param VendorServices $model the model to be validated
	 */
	protected function performAjaxValidation($model)
	{
		if(isset($_POST['ajax']) && $_POST['ajax']==='vendor-services-form')
		{
			echo CActiveForm::validate($model);
			Yii::app()->end();
		}
	}
}
