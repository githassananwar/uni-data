﻿//------------------------------------------------------------------------------
// <auto-generated>
//    This code was generated from a template.
//
//    Manual changes to this file may cause unexpected behavior in your application.
//    Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.ComponentModel;
using System.Data.EntityClient;
using System.Data.Objects;
using System.Data.Objects.DataClasses;
using System.Linq;
using System.Runtime.Serialization;
using System.Xml.Serialization;

[assembly: EdmSchemaAttribute()]
namespace finalProject.Models
{
    #region Contexts
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    public partial class finalDataBaseEntities2 : ObjectContext
    {
        #region Constructors
    
        /// <summary>
        /// Initializes a new finalDataBaseEntities2 object using the connection string found in the 'finalDataBaseEntities2' section of the application configuration file.
        /// </summary>
        public finalDataBaseEntities2() : base("name=finalDataBaseEntities2", "finalDataBaseEntities2")
        {
            this.ContextOptions.LazyLoadingEnabled = true;
            OnContextCreated();
        }
    
        /// <summary>
        /// Initialize a new finalDataBaseEntities2 object.
        /// </summary>
        public finalDataBaseEntities2(string connectionString) : base(connectionString, "finalDataBaseEntities2")
        {
            this.ContextOptions.LazyLoadingEnabled = true;
            OnContextCreated();
        }
    
        /// <summary>
        /// Initialize a new finalDataBaseEntities2 object.
        /// </summary>
        public finalDataBaseEntities2(EntityConnection connection) : base(connection, "finalDataBaseEntities2")
        {
            this.ContextOptions.LazyLoadingEnabled = true;
            OnContextCreated();
        }
    
        #endregion
    
        #region Partial Methods
    
        partial void OnContextCreated();
    
        #endregion
    
        #region ObjectSet Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        public ObjectSet<Accepter> Accepters
        {
            get
            {
                if ((_Accepters == null))
                {
                    _Accepters = base.CreateObjectSet<Accepter>("Accepters");
                }
                return _Accepters;
            }
        }
        private ObjectSet<Accepter> _Accepters;
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        public ObjectSet<Contact> Contacts
        {
            get
            {
                if ((_Contacts == null))
                {
                    _Contacts = base.CreateObjectSet<Contact>("Contacts");
                }
                return _Contacts;
            }
        }
        private ObjectSet<Contact> _Contacts;
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        public ObjectSet<Donor> Donors
        {
            get
            {
                if ((_Donors == null))
                {
                    _Donors = base.CreateObjectSet<Donor>("Donors");
                }
                return _Donors;
            }
        }
        private ObjectSet<Donor> _Donors;

        #endregion

        #region AddTo Methods
    
        /// <summary>
        /// Deprecated Method for adding a new object to the Accepters EntitySet. Consider using the .Add method of the associated ObjectSet&lt;T&gt; property instead.
        /// </summary>
        public void AddToAccepters(Accepter accepter)
        {
            base.AddObject("Accepters", accepter);
        }
    
        /// <summary>
        /// Deprecated Method for adding a new object to the Contacts EntitySet. Consider using the .Add method of the associated ObjectSet&lt;T&gt; property instead.
        /// </summary>
        public void AddToContacts(Contact contact)
        {
            base.AddObject("Contacts", contact);
        }
    
        /// <summary>
        /// Deprecated Method for adding a new object to the Donors EntitySet. Consider using the .Add method of the associated ObjectSet&lt;T&gt; property instead.
        /// </summary>
        public void AddToDonors(Donor donor)
        {
            base.AddObject("Donors", donor);
        }

        #endregion

    }

    #endregion

    #region Entities
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    [EdmEntityTypeAttribute(NamespaceName="finalDataBaseModel", Name="Accepter")]
    [Serializable()]
    [DataContractAttribute(IsReference=true)]
    public partial class Accepter : EntityObject
    {
        #region Factory Method
    
        /// <summary>
        /// Create a new Accepter object.
        /// </summary>
        /// <param name="accepterId">Initial value of the AccepterId property.</param>
        public static Accepter CreateAccepter(global::System.Int32 accepterId)
        {
            Accepter accepter = new Accepter();
            accepter.AccepterId = accepterId;
            return accepter;
        }

        #endregion

        #region Simple Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=true, IsNullable=false)]
        [DataMemberAttribute()]
        public global::System.Int32 AccepterId
        {
            get
            {
                return _AccepterId;
            }
            set
            {
                if (_AccepterId != value)
                {
                    OnAccepterIdChanging(value);
                    ReportPropertyChanging("AccepterId");
                    _AccepterId = StructuralObject.SetValidValue(value, "AccepterId");
                    ReportPropertyChanged("AccepterId");
                    OnAccepterIdChanged();
                }
            }
        }
        private global::System.Int32 _AccepterId;
        partial void OnAccepterIdChanging(global::System.Int32 value);
        partial void OnAccepterIdChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Name
        {
            get
            {
                return _Name;
            }
            set
            {
                OnNameChanging(value);
                ReportPropertyChanging("Name");
                _Name = StructuralObject.SetValidValue(value, true, "Name");
                ReportPropertyChanged("Name");
                OnNameChanged();
            }
        }
        private global::System.String _Name;
        partial void OnNameChanging(global::System.String value);
        partial void OnNameChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String BloodGroup
        {
            get
            {
                return _BloodGroup;
            }
            set
            {
                OnBloodGroupChanging(value);
                ReportPropertyChanging("BloodGroup");
                _BloodGroup = StructuralObject.SetValidValue(value, true, "BloodGroup");
                ReportPropertyChanged("BloodGroup");
                OnBloodGroupChanged();
            }
        }
        private global::System.String _BloodGroup;
        partial void OnBloodGroupChanging(global::System.String value);
        partial void OnBloodGroupChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Gender
        {
            get
            {
                return _Gender;
            }
            set
            {
                OnGenderChanging(value);
                ReportPropertyChanging("Gender");
                _Gender = StructuralObject.SetValidValue(value, true, "Gender");
                ReportPropertyChanged("Gender");
                OnGenderChanged();
            }
        }
        private global::System.String _Gender;
        partial void OnGenderChanging(global::System.String value);
        partial void OnGenderChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String City
        {
            get
            {
                return _City;
            }
            set
            {
                OnCityChanging(value);
                ReportPropertyChanging("City");
                _City = StructuralObject.SetValidValue(value, true, "City");
                ReportPropertyChanged("City");
                OnCityChanged();
            }
        }
        private global::System.String _City;
        partial void OnCityChanging(global::System.String value);
        partial void OnCityChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Email
        {
            get
            {
                return _Email;
            }
            set
            {
                OnEmailChanging(value);
                ReportPropertyChanging("Email");
                _Email = StructuralObject.SetValidValue(value, true, "Email");
                ReportPropertyChanged("Email");
                OnEmailChanged();
            }
        }
        private global::System.String _Email;
        partial void OnEmailChanging(global::System.String value);
        partial void OnEmailChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Contact
        {
            get
            {
                return _Contact;
            }
            set
            {
                OnContactChanging(value);
                ReportPropertyChanging("Contact");
                _Contact = StructuralObject.SetValidValue(value, true, "Contact");
                ReportPropertyChanged("Contact");
                OnContactChanged();
            }
        }
        private global::System.String _Contact;
        partial void OnContactChanging(global::System.String value);
        partial void OnContactChanged();

        #endregion

    }
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    [EdmEntityTypeAttribute(NamespaceName="finalDataBaseModel", Name="Contact")]
    [Serializable()]
    [DataContractAttribute(IsReference=true)]
    public partial class Contact : EntityObject
    {
        #region Factory Method
    
        /// <summary>
        /// Create a new Contact object.
        /// </summary>
        /// <param name="contactId">Initial value of the ContactId property.</param>
        public static Contact CreateContact(global::System.Int32 contactId)
        {
            Contact contact = new Contact();
            contact.ContactId = contactId;
            return contact;
        }

        #endregion

        #region Simple Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=true, IsNullable=false)]
        [DataMemberAttribute()]
        public global::System.Int32 ContactId
        {
            get
            {
                return _ContactId;
            }
            set
            {
                if (_ContactId != value)
                {
                    OnContactIdChanging(value);
                    ReportPropertyChanging("ContactId");
                    _ContactId = StructuralObject.SetValidValue(value, "ContactId");
                    ReportPropertyChanged("ContactId");
                    OnContactIdChanged();
                }
            }
        }
        private global::System.Int32 _ContactId;
        partial void OnContactIdChanging(global::System.Int32 value);
        partial void OnContactIdChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Name
        {
            get
            {
                return _Name;
            }
            set
            {
                OnNameChanging(value);
                ReportPropertyChanging("Name");
                _Name = StructuralObject.SetValidValue(value, true, "Name");
                ReportPropertyChanged("Name");
                OnNameChanged();
            }
        }
        private global::System.String _Name;
        partial void OnNameChanging(global::System.String value);
        partial void OnNameChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Email
        {
            get
            {
                return _Email;
            }
            set
            {
                OnEmailChanging(value);
                ReportPropertyChanging("Email");
                _Email = StructuralObject.SetValidValue(value, true, "Email");
                ReportPropertyChanged("Email");
                OnEmailChanged();
            }
        }
        private global::System.String _Email;
        partial void OnEmailChanging(global::System.String value);
        partial void OnEmailChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Message
        {
            get
            {
                return _Message;
            }
            set
            {
                OnMessageChanging(value);
                ReportPropertyChanging("Message");
                _Message = StructuralObject.SetValidValue(value, true, "Message");
                ReportPropertyChanged("Message");
                OnMessageChanged();
            }
        }
        private global::System.String _Message;
        partial void OnMessageChanging(global::System.String value);
        partial void OnMessageChanged();

        #endregion

    }
    
    /// <summary>
    /// No Metadata Documentation available.
    /// </summary>
    [EdmEntityTypeAttribute(NamespaceName="finalDataBaseModel", Name="Donor")]
    [Serializable()]
    [DataContractAttribute(IsReference=true)]
    public partial class Donor : EntityObject
    {
        #region Factory Method
    
        /// <summary>
        /// Create a new Donor object.
        /// </summary>
        /// <param name="donorId">Initial value of the DonorId property.</param>
        public static Donor CreateDonor(global::System.Int32 donorId)
        {
            Donor donor = new Donor();
            donor.DonorId = donorId;
            return donor;
        }

        #endregion

        #region Simple Properties
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=true, IsNullable=false)]
        [DataMemberAttribute()]
        public global::System.Int32 DonorId
        {
            get
            {
                return _DonorId;
            }
            set
            {
                if (_DonorId != value)
                {
                    OnDonorIdChanging(value);
                    ReportPropertyChanging("DonorId");
                    _DonorId = StructuralObject.SetValidValue(value, "DonorId");
                    ReportPropertyChanged("DonorId");
                    OnDonorIdChanged();
                }
            }
        }
        private global::System.Int32 _DonorId;
        partial void OnDonorIdChanging(global::System.Int32 value);
        partial void OnDonorIdChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Name
        {
            get
            {
                return _Name;
            }
            set
            {
                OnNameChanging(value);
                ReportPropertyChanging("Name");
                _Name = StructuralObject.SetValidValue(value, true, "Name");
                ReportPropertyChanged("Name");
                OnNameChanged();
            }
        }
        private global::System.String _Name;
        partial void OnNameChanging(global::System.String value);
        partial void OnNameChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Gender
        {
            get
            {
                return _Gender;
            }
            set
            {
                OnGenderChanging(value);
                ReportPropertyChanging("Gender");
                _Gender = StructuralObject.SetValidValue(value, true, "Gender");
                ReportPropertyChanged("Gender");
                OnGenderChanged();
            }
        }
        private global::System.String _Gender;
        partial void OnGenderChanging(global::System.String value);
        partial void OnGenderChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String BloodGroup
        {
            get
            {
                return _BloodGroup;
            }
            set
            {
                OnBloodGroupChanging(value);
                ReportPropertyChanging("BloodGroup");
                _BloodGroup = StructuralObject.SetValidValue(value, true, "BloodGroup");
                ReportPropertyChanged("BloodGroup");
                OnBloodGroupChanged();
            }
        }
        private global::System.String _BloodGroup;
        partial void OnBloodGroupChanging(global::System.String value);
        partial void OnBloodGroupChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String DOB
        {
            get
            {
                return _DOB;
            }
            set
            {
                OnDOBChanging(value);
                ReportPropertyChanging("DOB");
                _DOB = StructuralObject.SetValidValue(value, true, "DOB");
                ReportPropertyChanged("DOB");
                OnDOBChanged();
            }
        }
        private global::System.String _DOB;
        partial void OnDOBChanging(global::System.String value);
        partial void OnDOBChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String City
        {
            get
            {
                return _City;
            }
            set
            {
                OnCityChanging(value);
                ReportPropertyChanging("City");
                _City = StructuralObject.SetValidValue(value, true, "City");
                ReportPropertyChanged("City");
                OnCityChanged();
            }
        }
        private global::System.String _City;
        partial void OnCityChanging(global::System.String value);
        partial void OnCityChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Cnic
        {
            get
            {
                return _Cnic;
            }
            set
            {
                OnCnicChanging(value);
                ReportPropertyChanging("Cnic");
                _Cnic = StructuralObject.SetValidValue(value, true, "Cnic");
                ReportPropertyChanged("Cnic");
                OnCnicChanged();
            }
        }
        private global::System.String _Cnic;
        partial void OnCnicChanging(global::System.String value);
        partial void OnCnicChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Email
        {
            get
            {
                return _Email;
            }
            set
            {
                OnEmailChanging(value);
                ReportPropertyChanging("Email");
                _Email = StructuralObject.SetValidValue(value, true, "Email");
                ReportPropertyChanged("Email");
                OnEmailChanged();
            }
        }
        private global::System.String _Email;
        partial void OnEmailChanging(global::System.String value);
        partial void OnEmailChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Password
        {
            get
            {
                return _Password;
            }
            set
            {
                OnPasswordChanging(value);
                ReportPropertyChanging("Password");
                _Password = StructuralObject.SetValidValue(value, true, "Password");
                ReportPropertyChanged("Password");
                OnPasswordChanged();
            }
        }
        private global::System.String _Password;
        partial void OnPasswordChanging(global::System.String value);
        partial void OnPasswordChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Contact
        {
            get
            {
                return _Contact;
            }
            set
            {
                OnContactChanging(value);
                ReportPropertyChanging("Contact");
                _Contact = StructuralObject.SetValidValue(value, true, "Contact");
                ReportPropertyChanged("Contact");
                OnContactChanged();
            }
        }
        private global::System.String _Contact;
        partial void OnContactChanging(global::System.String value);
        partial void OnContactChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String Address
        {
            get
            {
                return _Address;
            }
            set
            {
                OnAddressChanging(value);
                ReportPropertyChanging("Address");
                _Address = StructuralObject.SetValidValue(value, true, "Address");
                ReportPropertyChanged("Address");
                OnAddressChanged();
            }
        }
        private global::System.String _Address;
        partial void OnAddressChanging(global::System.String value);
        partial void OnAddressChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String SourcePath
        {
            get
            {
                return _SourcePath;
            }
            set
            {
                OnSourcePathChanging(value);
                ReportPropertyChanging("SourcePath");
                _SourcePath = StructuralObject.SetValidValue(value, true, "SourcePath");
                ReportPropertyChanged("SourcePath");
                OnSourcePathChanged();
            }
        }
        private global::System.String _SourcePath;
        partial void OnSourcePathChanging(global::System.String value);
        partial void OnSourcePathChanged();
    
        /// <summary>
        /// No Metadata Documentation available.
        /// </summary>
        [EdmScalarPropertyAttribute(EntityKeyProperty=false, IsNullable=true)]
        [DataMemberAttribute()]
        public global::System.String rank
        {
            get
            {
                return _rank;
            }
            set
            {
                OnrankChanging(value);
                ReportPropertyChanging("rank");
                _rank = StructuralObject.SetValidValue(value, true, "rank");
                ReportPropertyChanged("rank");
                OnrankChanged();
            }
        }
        private global::System.String _rank;
        partial void OnrankChanging(global::System.String value);
        partial void OnrankChanged();

        #endregion

    }

    #endregion

}