<?php

class EventServicesController extends Controller
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
		$model=new EventServices;

		// Uncomment the following line if AJAX validation is needed
		// $this->performAjaxValidation($model);

		if(isset($_POST['EventServices']))
		{
			$model->attributes=$_POST['EventServices'];
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

		if(isset($_POST['EventServices']))
		{
			$model->attributes=$_POST['EventServices'];
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
	public function actiondeleteEventService($id, $eventid)
	{
		if(isset($_SESSION["login_admin"]))
		{
			$model=$this->loadModel($id);
        	
        	$event=Event::model()->findByAttributes(array('id'=>$eventid));
			$service=VendorServices::model()->findByAttributes(array('id'=>$model->vendor_service_id));
			
			if($service->pricemode=='Per Head')
			{
				$event->current_budget=$event->current_budget-( $event->numOfGuests*$service->price );
			}
			else
			{
				$event->current_budget=$event->current_budget-$service->price ;
			}
			$event->save();
			$model->delete();
			$this->redirect('?r=admin/manageOrders');
		}
		else if (isset($_SESSION['user-type']) && !strcmp($_SESSION['user-type'],"customer"))
		{
        	$model=$this->loadModel($id);

        	$event=Event::model()->findByAttributes(array('id'=>$eventid));
			$service=VendorServices::model()->findByAttributes(array('id'=>$model->vendor_service_id));
			
			if($service->pricemode=='Per Head')
			{
				$event->current_budget=$event->current_budget-( $event->numOfGuests*$service->price );
			}
			else
			{
				$event->current_budget=$event->current_budget-$service->price ;
			}
			$event->save();
			$model->delete();
			
			$this->redirect('?r=event/view&id='.$eventid);
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
		$dataProvider=new CActiveDataProvider('EventServices');
		$this->render('index',array(
			'dataProvider'=>$dataProvider,
		));
	}

	public function actionViewCustomerRequests()
	{
		
		$this->render('viewCustomerRequests');
	}

	public function actioncustomerRequests()
	{
		
		$this->renderPartial('customerRequests');
	}



	public function actionconfirmRequest($id)
	{
		if( isset($_SESSION['login_user']) )
		{
			$model=$this->loadModel($id);
			$model->status="Confirm";
			$model->update();
			print "confirm";
		}

	}


	
	public function actioncancelRequest($id)
	{
		if( isset($_SESSION['login_user']) )
		{
			$model=$this->loadModel($id);
			$model->status="Cancelled";
			$model->update();
			print "cancelled";
		}

	}

	/**
	 * Manages all models.
	 */
	public function actionAdmin()
	{
		$model=new EventServices('search');
		$model->unsetAttributes();  // clear any default values
		if(isset($_GET['EventServices']))
			$model->attributes=$_GET['EventServices'];

		$this->render('admin',array(
			'model'=>$model,
		));
	}

	/**
	 * Returns the data model based on the primary key given in the GET variable.
	 * If the data model is not found, an HTTP exception will be raised.
	 * @param integer $id the ID of the model to be loaded
	 * @return EventServices the loaded model
	 * @throws CHttpException
	 */
	public function loadModel($id)
	{
		$model=EventServices::model()->findByPk($id);
		if($model===null)
			throw new CHttpException(404,'The requested page does not exist.');
		return $model;
	}

	/**
	 * Performs the AJAX validation.
	 * @param EventServices $model the model to be validated
	 */
	protected function performAjaxValidation($model)
	{
		if(isset($_POST['ajax']) && $_POST['ajax']==='event-services-form')
		{
			echo CActiveForm::validate($model);
			Yii::app()->end();
		}
	}
}
