(function($) {
    "use strict";

    /**
     * Table of Contents:
     *
     * 01 - Document Ready
     * 02 - Window Load
     * 03 - Window scroll
     * 04 - Platform detect
     * 05 - collapsed menu close on click
     * 06 - collapsed menu close on click
     * 07 - Menuzord - Responsive Megamenu
     * 08 - Waypoint Top Nav Sticky
     * 09 - Active Menu Item on Reaching Different Sections
     * 10 - home section on scroll parallax & fade
     * 11 - on click scrool to target with smoothness
     * 12 - Scroll navigation
     * 13 - scrollToTop
     * 14 - Background image, color
       * 14.1 - Background Parallax
     * 15 - Team Hover Effect
     * 16 - Home Resize Fullscreen
     * 17 - lightbox popup
     * 18 - Owl Carousel
     * 19 - BX Slider
     * 20 - Nivo Lightbox
     * 21 - progress bar / horizontal skill bar
     * 22 - Funfact Number Counter
     * 23 - Isotope
     * 24 - Contact Form
     * 25 - Wow initialize
     * 26 - Fit Vids
     * 27 - YT Player for Video
     * 28 - Flickr Feed
     * 29 - accordion & toggles
     * 30 - Horizontal & Vertical Tab
     * 31 - tooltip
     * 32 - Top search toggle
     * 33 - Twitter Feed
     * 34 - Maximage-slider
     * 35 - Mailchimp
     * 36 - equalHeights
     * 37 - Google-map
     * 38 - toggle Google map
     * -----------------------------------------------
     */

    /* ---------------------------------------------------------------------- */
    /* -------------------- 01 - Document Ready ----------------------------- */
    /* ---------------------------------------------------------------------- */
    $(window).trigger("resize");
    thememascot_lightboxPopup();
    thememascot_nivolightbox();
    thememascot_scrollToFixed();
    thememascot_topnav_animate();
    thememascot_scrolltoTarget();
    thememascot_menuzord();
    thememascot_navLocalScorll();
    thememascot_parallaxBgInit();
    thememascot_teamInit();
    thememascot_resize_fullscreen();
    thememascot_owlCarousel();
    thememascot_bxslider();
    thememascot_progress_bar();
    thememascot_funfact();
    thememascot_contactform();
    thememascot_wow();
    thememascot_fitVids();
    thememascot_YTPlayer();
    thememascot_jflickrfeed();
    thememascot_accordion_toggles();
    thememascot_tab();
    thememascot_tooltip();
    thememascot_topsearch_toggle();
    //thememascot_twittie();
    thememascot_maximageSlider();
    thememascot_mailChimp();
    thememascot_toggleMap();



    /* ---------------------------------------------------------------------- */
    /* ----------------------- 02 - Window Load ----------------------------- */
    /* ---------------------------------------------------------------------- */
    $(window).load(function() {
        //preloader
        $('#preloader').delay(200).fadeOut('slow');
        
        $(window).trigger("scroll");
        $(window).trigger("resize");
        
        // Hash Forwarding
        if (window.location.hash){
			var hash_offset = $(window.location.hash).offset().top;
			$("html, body").animate({
				scrollTop: hash_offset
			});
        }
    });

    /* ---------------------------------------------------------------------- */
    /* ------------------------- 03 - Window scroll ------------------------- */
    /* ---------------------------------------------------------------------- */
    $(window).scroll(function() {
        thememascot_topnav_animate();
        thememascot_home_parallax_fade_effect();
        thememascot_scrollToTop_icon();
        thememascot_activate_menuitem();
    });


  /* ---------------------------------------------------------------------- */
  /* -------------------------- 04 - Platform detect ------------------------- */
  /* ---------------------------------------------------------------------- */
    var isMobile;
    if (/Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent)) {
        isMobile = true;
        $("html").addClass("mobile");
    }
    else {
        isMobile = false;
        $("html").addClass("no-mobile");
    }

    
    /* ---------------------------------------------------------------------------- */
    /* ---------------------- 05 - collapsed menu close on click ------------------ */
    /* ---------------------------------------------------------------------------- */
    $(document).on('click', '.navbar-collapse.in', function (e) {
      if ($(e.target).is('a')) {
          $(this).collapse('hide');
      }
    });

    /* ---------------------------------------------------------------------------- */
    /* ---------------------- 06 - collapsed menu close on click ------------------ */
    /* ---------------------------------------------------------------------------- */
    function thememascot_scrollToFixed() {
        $('.navbar-scrolltofixed').scrollToFixed();
    }

    /* ----------------------------------------------------------------------------- */
    /* ---------------------- 07 - Menuzord - Responsive Megamenu ------------------ */
    /* ----------------------------------------------------------------------------- */
    function thememascot_menuzord() {
        $("#menuzord").menuzord({
            align: "left",
            effect: "slide",
            animation: "none",
            indicatorFirstLevel: "<i class='fa fa-angle-down'></i>",
            indicatorSecondLevel: "<i class='fa fa-angle-right'></i>"
        });
        $("#menuzord-right").menuzord({
            align: "right",
            effect: "slide",
            animation: "none",
            indicatorFirstLevel: "<i class='fa fa-angle-down'></i>",
            indicatorSecondLevel: "<i class='fa fa-angle-right'></i>"
        });
    }

    /* ---------------------------------------------------------------------- */
    /* ---------------------- 08 - Waypoint Top Nav Sticky ------------------ */
    /* ---------------------------------------------------------------------- */
    function thememascot_topnav_animate() {
      if ($(window).scrollTop() > (50)) {
            $(".navbar-sticky-animated").removeClass("animated-active");
        } else {
            $(".navbar-sticky-animated").addClass("animated-active");
        }

        if ($(window).scrollTop() > (50)) {
            $(".navbar-sticky-animated .header-nav-wrapper .container").removeClass("pt-20").removeClass("pb-20");
        } else {
            $(".navbar-sticky-animated .header-nav-wrapper .container").addClass("pt-20").addClass("pb-20");
        }
    }

    /* ---------------------------------------------------------------------- */
    /* ------ 09 - Active Menu Item on Reaching Different Sections ---------- */
    /* ---------------------------------------------------------------------- */
    //Active Menu Item on Reaching Different Sections
    var sections = $('section'),
        nav = $('header'),
        nav_height = nav.outerHeight();

    function thememascot_activate_menuitem() {
        var cur_pos = $(window).scrollTop() + 2;
        sections.each(function() {
            var top = $(this).offset().top - nav_height - 80,
                bottom = top + $(this).outerHeight();

            if (cur_pos >= top && cur_pos <= bottom) {
                nav.find('a').removeClass('current').removeClass('active');
                sections.removeClass('current').removeClass('active');

                //$(this).addClass('current').addClass('active');
                nav.find('a[href="#' + $(this).attr('id') + '"]').addClass('current').addClass('active');
            }
        });
    }


    /* ---------------------------------------------------------------------- */
    /* ----------- 10 - home section on scroll parallax & fade -------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_home_parallax_fade_effect() {
        if ($(window).width() >= 1200) {
            var scrolled = $(window).scrollTop();
            $('.content-fade-effect .display-table .display-table-cell').css('padding-top', (scrolled * 0.0610) + '%');
            $('.content-fade-effect .display-table .display-table-cell').css('opacity', 1 - (scrolled * 0.00120));
        }
    }


    /* ---------------------------------------------------------------------- */
    /* -------------- 11 - on click scrool to target with smoothness -------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_scrolltoTarget() {
        //jQuery for page scrolling feature - requires jQuery Easing plugin
        $('.smooth-scroll').on('click', function(event) {
            var $anchor = $(this);
            $('html, body').stop().animate({
                scrollTop: $($anchor.attr('href')).offset().top + 80
            }, 1500, 'easeInOutExpo');
            event.preventDefault();
        });
    }

    /* ---------------------------------------------------------------------- */
    /* --------------------- 12 - Scroll navigation ------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_navLocalScorll() {
		var	data_offset = -60;
        $(".menuzord-menu").localScroll({
            target: "body",
            duration: 800,
			offset: data_offset,
            easing: "easeInOutExpo"
        });
    }


    /* ---------------------------------------------------------------------- */
    /* -------------------------- 13 - scrollToTop  ------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_scrollToTop_icon() {
        if ($(window).scrollTop() > 600) {
            $('.scrollToTop').fadeIn();
        } else {
            $('.scrollToTop').fadeOut();
        }
    }

    $(document.body).on('click', '.scrollToTop', function(e) {
        $('html, body').animate({
            scrollTop: 0
        }, 800);
        return false;
    });


  /* ---------------------------------------------------------------------- */
  /* -------------------- 14 - Background image, color -------------------- */
  /* ---------------------------------------------------------------------- */
  $('[data-bg-color]').each(function() {
    $(this).css("cssText", "background: " + $(this).data("bg-color") + " !important;");
  });
  $('[data-bg-img]').each(function() {
    $(this).css('background-image', 'url(' + $(this).data("bg-img") + ')');
  });
  $('[data-text-color]').each(function() {
    $(this).css('color', $(this).data("text-color"));
  });
  $('[data-font-size]').each(function() {
    $(this).css('font-size', $(this).data("font-size"));
  });
  $('[data-height]').each(function() {
    $(this).css('height', $(this).data("height"));
  });
  $('[data-border]').each(function() {
    $(this).css('border', $(this).data("border"));
  });

    /* ---------------------------------------------------------------------- */
    /* ---------------------- 14.1 - Background Parallax -------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_parallaxBgInit() {
        if (($(window).width() >= 1200) && (isMobile === false)) {
            $('.parallax').each(function() {
                $(this).parallax("50%", 0.1);
            });
        }
    }
    $(window).bind('load', function() {
        thememascot_parallaxBgInit();
    });


    /* ---------------------------------------------------------------------- */
    /* ----------------------- 15 - Team Hover Effect ----------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_teamInit() {
        $(document.body).on('touchstart click', '.team-member', function(e) {
            if ( $("html").hasClass("mobile") ) {
                $(this).toggleClass("js-active");
            }
        });        
    }



    /* ---------------------------------------------------------------------- */
    /* ------------------------ 16 - Home Resize Fullscreen ----------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_resize_fullscreen() {
        var windowHeight = $(window).height();
        $('.fullscreen, .revslider-fullscreen').height(windowHeight);
    }
    $(window).resize(function() {
        thememascot_resize_fullscreen();
    });

    /* ---------------------------------------------------------------------- */
    /* -------------------------- 17 - lightbox popup ----------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_lightboxPopup() {
          lightbox.option({
          resizeDuration: 200,
          alwaysShowNavOnTouchDevices: true,
          positionFromTop: 50,
          wrapAround: true
        });

        $("a[data-rel^='prettyPhoto']").prettyPhoto({
            hook: 'data-rel',
            animation_speed:'normal',
            theme:'light_square',
            slideshow:3000, 
            autoplay_slideshow: false,
            social_tools: false
        });

    }

    /* ---------------------------------------------------------------------- */
    /* ---------------------------- 18 - Owl Carousel  ---------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_owlCarousel() {

        $(".text-carousel").owlCarousel({
            autoplay: true,
            autoplayTimeout: 2000,
            loop: true,
            items: 1,
            dots: true,
            nav: false,
            navText: [
                '<i class="pe-7s-angle-left"></i>',
                '<i class="pe-7s-angle-right"></i>'
            ]
        });

        $(".image-carousel").owlCarousel({
            autoplay: true,
            autoplayTimeout: 2000,
            smartSpeed: 400,
            items: 1,
            loop: true,
            dots: true,
            nav: false,
            navText: [
                '<i class="pe-7s-angle-left"></i>',
                '<i class="pe-7s-angle-right"></i>'
            ]
        });
		
        $(".gallery-list-carosel").owlCarousel({
            autoplay: false,
            autoplayTimeout: 4000,
            loop: true,
            margin: 15,
            dots: false,
            nav: true,
            navText: [
                '<i class="fa fa-angle-left"></i>',
                '<i class="fa fa-angle-right"></i>'
            ],
            responsive: {
                0: {
                    items: 2,
                    center: false
                },
                600: {
                    items: 4,
                    center: false
                },
                960: {
                    items: 6
                },
                1170: {
                    items: 6
                },
                1300: {
                    items: 6
                }
            }
        });

        $(".testimonial-carousel").owlCarousel({
            autoplay: false,
            autoplayTimeout: 4000,
            loop: true,
            margin: 15,
            dots: false,
            nav: true,
            navText: [
                '<i class="fa fa-angle-left"></i>',
                '<i class="fa fa-angle-right"></i>'
            ],
            responsive: {
                0: {
                    items: 1,
                    center: false
                },
                600: {
                    items: 1,
                    center: false
                },
                960: {
                    items: 1
                },
                1170: {
                    items: 1
                },
                1300: {
                    items: 1
                }
            }
        });

        $(".featured-project-carousel").owlCarousel({
            autoplay: false,
            autoplayTimeout: 4000,
            loop: true,
            margin: 15,
            dots: false,
            nav: true,
            navText: [
                '<i class="fa fa-angle-left"></i>',
                '<i class="fa fa-angle-right"></i>'
            ],
            responsive: {
                0: {
                    items: 1,
                    center: false
                },
                600: {
                    items: 1,
                    center: false
                },
                960: {
                    items: 1
                },
                1170: {
                    items: 1
                },
                1300: {
                    items: 1
                }
            }
        });

        $('.news-carousel').each(function() {
            var data_dots = ( $(this).data("dots") === undefined ) ? false: $(this).data("dots");
            var data_nav = ( $(this).data("nav") === undefined ) ? false: $(this).data("nav");
            $(this).owlCarousel({
                autoplay: false,
                autoplayTimeout: 4000,
                loop: true,
                margin: 15,
                dots: data_dots,
                nav: data_nav,
                navText: [
                    '<i class="fa fa-angle-left"></i>',
                    '<i class="fa fa-angle-right"></i>'
                ],
                responsive: {
                    0: {
                        items: 1,
                        center: false
                    },
                    600: {
                        items: 1,
                        center: false
                    },
                    750: {
                        items: 3,
                        center: false
                    },
                    960: {
                        items: 3
                    },
                    1170: {
                        items: 3
                    },
                    1300: {
                        items: 3
                    }
                }
            });
        });

        $('.news-carousel-2column').each(function() {
            var data_dots = ( $(this).data("dots") === undefined ) ? false: $(this).data("dots");
            var data_nav = ( $(this).data("nav")=== undefined ) ? false: $(this).data("nav");
            console.log(data_dots);
            console.log(data_nav);
            $(this).owlCarousel({
                autoplay: false,
                autoplayTimeout: 4000,
                loop: true,
                margin: 15,
                dots: data_dots,
                nav: data_nav,
                navText: [
                    '<i class="fa fa-angle-left"></i>',
                    '<i class="fa fa-angle-right"></i>'
                ],
                responsive: {
                    0: {
                        items: 1,
                        center: false
                    },
                    600: {
                        items: 1,
                        center: false
                    },
                    750: {
                        items: 2,
                        center: false
                    },
                    960: {
                        items: 2
                    },
                    1170: {
                        items: 2
                    },
                    1300: {
                        items: 2
                    }
                }
            });
        });
        
        $(".clients-logo.carousel").owlCarousel({
            autoplay: true,
            autoplayTimeout: 2000,
            items: 5,
            dots: false,
            nav: false,
            responsive: {
                0: {
                    items: 3,
                    center: false
                },
                600: {
                    items: 3,
                    center: false
                },
                960: {
                    items: 4
                },
                1170: {
                    items: 6
                },
                1300: {
                    items: 6
                }
            }
        });

        $('.causes-carousel').each(function() {
            var data_dots = ( $(this).data("dots") === undefined ) ? false: $(this).data("dots");
            var data_nav = ( $(this).data("nav") === undefined ) ? false: $(this).data("nav");
            $(this).owlCarousel({
                autoplay: true,
                autoplayTimeout: 4000,
                loop: true,
                margin: 15,
                dots: data_dots,
                nav: data_nav,
                navText: [
                    '<i class="fa fa-angle-left"></i>',
                    '<i class="fa fa-angle-right"></i>'
                ],
                responsive: {
                    0: {
                        items: 1,
                        center: false
                    },
                    600: {
                        items: 1,
                        center: false
                    },
                    750: {
                        items: 2,
                        center: false
                    },
                    960: {
                        items: 3
                    },
                    1170: {
                        items: 4
                    },
                    1300: {
                        items: 4
                    }
                }
            });
        });

        $('.volunteers-carousel').each(function() {
            var data_dots = ( $(this).data("dots") === undefined ) ? false: $(this).data("dots");
            var data_nav = ( $(this).data("nav") === undefined ) ? false: $(this).data("nav");
            $(this).owlCarousel({
                autoplay: true,
                autoplayTimeout: 4000,
                loop: true,
                margin: 15,
                dots: data_dots,
                nav: data_nav,
                navText: [
                    '<i class="fa fa-angle-left"></i>',
                    '<i class="fa fa-angle-right"></i>'
                ],
                responsive: {
                    0: {
                        items: 1,
                        center: false
                    },
                    600: {
                        items: 1,
                        center: false
                    },
                    750: {
                        items: 2,
                        center: false
                    },
                    960: {
                        items: 3
                    },
                    1170: {
                        items: 4
                    },
                    1300: {
                        items: 4
                    }
                }
            });
        });

        $(".fullwidth-carousel").owlCarousel({
            autoplay: true,
            autoplayTimeout: 5000,
            loop: true,
            items: 1,
            dots: false,
            nav: true,
            navText: [
                '<i class="pe-7s-angle-left"></i>',
                '<i class="pe-7s-angle-right"></i>'
            ]
        });
        
    }

    /* ---------------------------------------------------------------------- */
    /* ---------------------------- 19 - BX Slider  ------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_bxslider() {
        $('.bxslider').bxSlider({
            mode: 'vertical',
            minSlides: 3,
            slideMargin: 20,
            pager: false,
            prevText: '<i class="fa fa-angle-left"></i>',
            nextText: '<i class="fa fa-angle-right"></i>'
        });
    }
    
    /* ---------------------------------------------------------------------- */
    /* -------------------------- 20 - Nivo Lightbox ------------------------ */
    /* ---------------------------------------------------------------------- */ 
    function thememascot_nivolightbox() {
      $('a[data-lightbox-gallery]').nivoLightbox({
          effect: 'fadeScale'
      });
    }

    /* ---------------------------------------------------------------------- */
    /* ---------------- 21 - progress bar / horizontal skill bar ------------ */
    /* ---------------------------------------------------------------------- */
    function thememascot_progress_bar() {
        $('.progress-bar').appear();
        $(document.body).on('appear', '.progress-bar', function() {
            $('.progress-bar').each(function() {
                if (!$(this).hasClass('appeared')) {
                    var percent = $(this).data('percent');
                    var barcolor = $(this).data('barcolor');
                    $(this).append('<span class="percent">' + percent + '%' + '</span>');
                    $(this).css('background-color', barcolor);
                    $(this).css('width', percent + '%');
                    $(this).addClass('appeared');
                }
            });
        });
        $('.progress-bar-aa').each(function() {
            if (!$(this).hasClass('appeared')) {
                var percent = $(this).data('percent');
                var barcolor = $(this).data('barcolor');
                $(this).append('<span class="percent">' + percent + '%' + '</span>');
                $(this).css('background-color', barcolor);
                $(this).css('width', percent + '%');
                $(this).addClass('appeared');
            }
        });

    }

    /* ---------------------------------------------------------------------- */
    /* --------------------- 22 - Funfact Number Counter -------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_funfact() {
        $('.animate-number').appear();
        $(document.body).on('appear', '.animate-number', function() {
            $('.animate-number').each(function() {
                if (!$(this).hasClass('appeared')) {
                    $(this).animateNumbers($(this).attr("data-value"), true, parseInt($(this).attr("data-animation-duration"), 10));
                    $(this).addClass('appeared');
                }
            });
        });
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------------ 23 - Isotope -------------------------------- */
    /* ---------------------------------------------------------------------- */
    function reorganizeIsotope() {
      jQuery('.masonry-items').each(function() {
          var $container = jQuery(this);
          var maxitemwidth = $container.data('maxitemwidth');
          if (!maxitemwidth) {
              maxitemwidth = 370;
          }
          var containerwidth = Math.ceil((($container.width() + (parseInt($container.css('marginLeft'), 10) * 2)) / 120) * 100 - (parseInt($container.css('marginLeft'), 10) * 2));
          //alert(containerwidth);
          var itemmargin = parseInt($container.children('div').css('marginRight'), 10) + parseInt($container.children('div').css('marginLeft'), 10);
          var rows = Math.ceil(containerwidth / maxitemwidth);
          var marginperrow = (rows - 1) * itemmargin;
          var newitemmargin = marginperrow / rows;
          var itemwidth = Math.floor((containerwidth / rows) - newitemmargin + 1);
          //$container.css({ 'width': '110%' });
          $container.children('div').css({
              'width': itemwidth + 'px'
          });
          if ($container.children('div').hasClass('isotope-item')) {
              $container.isotope('reLayout');
          }
      });
    }
    if (jQuery().isotope) {
      /* isotop call */
      jQuery('.masonry-items').each(function() {
          var $container = jQuery(this);
          $container.imagesLoaded(function() {
              $container.isotope({
                  itemSelector: '.masonry-item',
                  transformsEnabled: true // Important for videos
              });
          });
      });

      /* isotop filter */
      $(document.body).on('click', '.masonry-filters li a', function(e) {
          var parentul = jQuery(this).parents('ul.masonry-filters').data('related-grid');
          jQuery(this).parents('ul.masonry-filters').find('li a').removeClass('active');
          jQuery(this).addClass('active');
          var selector = jQuery(this).attr('data-option-value');
          jQuery('#' + parentul).isotope({
              filter: selector
          }, function() {});

          return (false);
      });
      
      reorganizeIsotope();
      jQuery(window).resize(function() {
          reorganizeIsotope();
      });
    } /* END if isotope */

    
    /* ---------------------------------------------------------------------- */
    /* -------------------------- 24 - Contact Form ------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_contactform() {
        var $contactform = $('#contact-form'),
            $response = '';

        // After contact form submit
        $contactform.submit(function() {
            // Hide any previous response text
            $contactform.children(".alert").remove();

            // Are all the fields filled in? 
            if (!$('#contact_name').val()) {
                $response = '<div class="alert alert-danger">Please enter your name.</div>';
                $('#contact_name').focus();
                $contactform.append($response);

            } else if (!$('#contact_message').val()) {
                $response = '<div class="alert alert-danger">Please enter your message.</div>';
                $('#contact_message').focus();
                $contactform.append($response);

            } else if (!$('#contact_email').val()) {
                $response = '<div class="alert alert-danger">Please enter valid e-mail.</div>';
                $('#contact_email').focus();
                $contactform.append($response);

            } else {
                // Yes, submit the form to the PHP script via Ajax 
                $contactform.children('button[type="submit"]').button('loading');
                $.ajax({
                    type: "POST",
                    url: "php/contact-form.php",
                    data: $(this).serialize(),
                    success: function(msg) {
                        if (msg == 'sent') {
                            $response = '<div class="alert alert-success">Your message has been sent. Thank you!</div>';
                            $contactform[0].reset();
                        } else {
                            $response = '<div class="alert alert-danger">' + msg + '</div>';
                        }
                        // Show response message
                        $contactform.append($response);
                        $contactform.children('button[type="submit"]').button('reset');
                    }
                });
            }
            return false;
        });
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------------- 25 - Wow initialize  ----------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_wow() {
        var wow = new WOW({
            mobile: false // trigger animations on mobile devices (default is true)
        });
        wow.init();
    }

    /* ---------------------------------------------------------------------- */
    /* -------------------------- 26 - Fit Vids ----------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_fitVids() {
        $('body').fitVids();
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------------- 27 - YT Player for Video ------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_YTPlayer() {
        $(".player").mb_YTPlayer();
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------------- 28 - Flickr Feed --------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_jflickrfeed() {
        $(".flickr-widget .flickr-feed").jflickrfeed({
            limit: 9,
            qstrings: {
                id: "64742456@N00"
            },
            itemTemplate: '<a href="{{link}}" title="{{title}}" target="_blank"><img src="{{image_m}}" alt="{{title}}">  </a>'
        });
    }

    /* ---------------------------------------------------------------------- */
    /* --------------------- 29 - accordion & toggles ----------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_accordion_toggles() {
        $(".panel-group .collapse").on("show.bs.collapse", function(e) {
            $(this).closest(".panel-group").find("[href='#" + $(this).attr("id") + "']").addClass("active");
        });
        $(".panel-group .collapse").on("hide.bs.collapse", function(e) {
            $(this).closest(".panel-group").find("[href='#" + $(this).attr("id") + "']").removeClass("active");
        });
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------ 30 - Horizontal & Vertical Tab   ------------------ */
    /* ---------------------------------------------------------------------- */
    function thememascot_tab() {
        var tpl_tab_height;
        $(document.body).on('click', '.tpl-minimal-tabs > li > a', function(e) {
            if (!($(this).parent("li").hasClass("active"))) {
                tpl_tab_height = $(".tpl-minimal-tabs-cont > .tab-pane").filter($(this).attr("href")).height();
                $(".tpl-minimal-tabs-cont").animate({
                    height: tpl_tab_height
                }, function() {
                    $(".tpl-minimal-tabs-cont").css("height", "auto");
                });
            }
        });

        $(document.body).on('click', '.tab-slider .nav.nav-pills a', function(e) {
            $(this).parent("div").parent("div").find('a').removeClass('active');
            $(this).addClass('active');

            var hash_offset = $($(this).data('parent')).offset().top;
            console.log(hash_offset);
            $('html, body').stop().animate({
                scrollTop: hash_offset - $('.header-nav').outerHeight()
            }, 800, 'easeInOutExpo');
        });
    }

    /* ---------------------------------------------------------------------- */
    /* ---------------------------- 31 - tooltip  --------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_tooltip() {
        $('[data-toggle="tooltip"]').tooltip();
    }

    /* ---------------------------------------------------------------------- */
    /* ---------------------- 32 - Top search toggle  ----------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_topsearch_toggle() {
        $(document.body).on('click', '#top-search-toggle', function(e) {
            e.preventDefault();
            $('.search-form-wrapper.toggle').toggleClass('active');
        });
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------------ 33 - Twitter Feed  -------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_twittie() {
        $('.twitter-feed').twittie({
            username: 'Envato',
            dateFormat: '%b. %d, %Y',
            template: '{{tweet}} <div class="date">{{date}}</div>',
            count: 2,
            loadingText: 'Loading!'
        }, function() {
            $(".twitter-carousel ul").owlCarousel({
                autoplay: true,
                autoplayTimeout: 2000,
                loop: true,
                items: 1,
                dots: true,
                nav: false
            });
        });
    }
    
    /* ---------------------------------------------------------------------- */
    /* ---------- 34 - maximage Fullscreen Background Slider ---------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_maximageSlider() {
        $('#maximage').maximage({
            cycleOptions: {
                fx: 'fade',
                speed: 1500,
                prev: '.img-prev',
                next: '.img-next'
            }
        });
    }

    /* ---------------------------------------------------------------------- */
    /* --------------------------- 35 - Mailchimp --------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_mailChimp() {

        //mailchimp-subscription-form
        $('#mailchimp-subscription-form').ajaxChimp({
            callback: mailChimpCallBack,
            url: '//thememascot.us9.list-manage.com/subscribe/post?u=a01f440178e35febc8cf4e51f&amp;id=49d6d30e1e'
        });
        function mailChimpCallBack(resp) {
            // Hide any previous response text
            var $mailchimpform = $('#mailchimp-subscription-form'),
                $response = '';
            $mailchimpform.children(".alert").remove();
            console.log(resp);
            if (resp.result === 'success') {
                $response = '<div class="alert alert-success"><button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' + resp.msg + '</div>';
            } else if (resp.result === 'error') {
                $response = '<div class="alert alert-danger"><button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' + resp.msg + '</div>';
            }
            $mailchimpform.prepend($response);
        }

        //footer-mailchimp-subscription-form
        $('#footer-mailchimp-subscription-form').ajaxChimp({
            callback: footerMailChimpCallBack,
            url: '//thememascot.us9.list-manage.com/subscribe/post?u=a01f440178e35febc8cf4e51f&amp;id=49d6d30e1e'
        });
        function footerMailChimpCallBack(resp) {
            // Hide any previous response text
            var $mailchimpform = $('#footer-mailchimp-subscription-form'),
                $response = '';
            $mailchimpform.children(".alert").remove();
            console.log(resp);
            if (resp.result === 'success') {
                $response = '<div class="alert alert-success"><button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' + resp.msg + '</div>';
            } else if (resp.result === 'error') {
                $response = '<div class="alert alert-danger"><button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' + resp.msg + '</div>';
            }
            $mailchimpform.prepend($response);
        }
    }

    /* ---------------------------------------------------------------------- */
    /* ------------------------- 36 - equalHeights -------------------------- */
    /* ---------------------------------------------------------------------- */ 
    function landapp_resizeDivs() {
      /* global equal heigh*/
      $('.equal-height > div').css('min-height', 'auto');
      $('.equal-height').equalHeights();

      /* funfact equal heigh*/
      $('.equal-height.funfact-equal-height > div > div').css('min-height', $('.equal-height.funfact-equal-height > div').css('min-height'));

      /* tab slider equal height */
      $('.tab-slider .equal-height > div > a').css('min-height', $('.tab-slider .equal-height > div').css('min-height'));
    }
    $(window).resize(function() {
      landapp_resizeDivs();
    });

    /* ---------------------------------------------------------------------- */
    /* -------------------------- 37 - Google-map --------------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_showMap(targetmap) {
        var ThemeMascot_googlemap_styles = {
            'default': [],
						
            'style1': [],
						            
            'style2': [{"featureType": "landscape","stylers": [{"hue": "#007FFF"},{"saturation": 100},{"lightness": 156},{"gamma": 1}]},{"featureType": "road.highway","stylers": [{"hue": "#FF7000"},{"saturation": -83.6},{"lightness": 48.80000000000001},{"gamma": 1}]},{"featureType": "road.arterial","stylers": [{"hue": "#FF7000"},{"saturation": -81.08108108108107},{"lightness": -6.8392156862745},{"gamma": 1}]},{"featureType": "road.local","stylers": [{"hue": "#FF9A00"},{"saturation": 7.692307692307736},{"lightness": 21.411764705882348},{"gamma": 1}]},{"featureType": "water","stylers": [{"hue": "#0093FF"},{"saturation": 16.39999999999999},{"lightness": -6.400000000000006},{"gamma": 1}]},{"featureType": "poi","stylers": [{"hue": "#00FF60"},{"saturation": 17},{"lightness": 44.599999999999994},{"gamma": 1}]}],
            
            'style3': [{stylers: [{ hue: "#00ffe6" },{ saturation: -20 }]},{featureType: "road",elementType: "geometry",stylers: [{ lightness: 100 },{ visibility: "simplified" }]},{featureType: "road",elementType: "labels",stylers: [{ visibility: "off" }]}],
            
            'style4': [{"stylers": [{ "saturation": -100 }]}],
            
            'style5': [{"featureType": "landscape","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 20.4705882352941 },{ "gamma": 1 }]},{"featureType": "road.highway","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 25.59999999999998 },{ "gamma": 1 }]},{"featureType": "road.arterial","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": -22 },{ "gamma": 1 }]},{"featureType": "road.local","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 21.411764705882348 },{ "gamma": 1 }]},{"featureType": "water","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 21.411764705882348 },{ "gamma": 1 }]},{"featureType": "poi","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 4.941176470588232 },{ "gamma": 1 }]}],
            
            'style6': [{"featureType": "landscape","stylers": [{ "hue": "#FF0300"  },{ "saturation": -100 },{ "lightness": 20.4705882352941 },{ "gamma": 1 }]},{"featureType": "road.highway","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 25.59999999999998 },{ "gamma": 1 }]},{"featureType": "road.arterial","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": -22 },{ "gamma": 1 }]},{"featureType": "road.local","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 21.411764705882348 },{ "gamma": 1 }]},{"featureType": "water","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 21.411764705882348 },{ "gamma": 1 }]},{"featureType": "poi","stylers": [{ "hue": "#FF0300" },{ "saturation": -100 },{ "lightness": 4.941176470588232 },{ "gamma": 1 }]}],
            
            'style7': [{"featureType":"landscape","stylers":[{ "invert_lightness": true },{"saturation":-100},{"lightness":65},{"visibility":"on"}]},{"featureType":"poi","stylers":[{"saturation":-100},{"lightness":51},{"visibility":"simplified"}]},{"featureType":"road.highway","stylers":[{"saturation":-100},{"visibility":"simplified"}]},{"featureType":"road.arterial","stylers":[{"saturation":-100},{"lightness":30},{"visibility":"on"}]},{"featureType":"road.local","stylers":[{"saturation":-100},{"lightness":40},{"visibility":"on"}]},{"featureType":"transit","stylers":[{"saturation":-100},{"visibility":"simplified"}]},{"featureType":"administrative.province","stylers":[{"visibility":"off"}]},{"featureType":"water","elementType":"labels","stylers":[{"visibility":"on"},{"lightness":-25},{"saturation":-100}]},{"featureType":"water","elementType":"geometry","stylers":[{"hue":"#ffff00"},{"lightness":-25},{"saturation":-97}]}],
						
            'style8':  [{"featureType": "landscape","stylers": [{"hue": "#FFA800"},{"saturation": 17.799999999999997},{"lightness": 152.20000000000002},{"gamma": 1}]},{"featureType": "road.highway","stylers": [{"hue": "#007FFF"},{"saturation": -77.41935483870967},{"lightness": 47.19999999999999},{"gamma": 1}]},{"featureType": "road.arterial","stylers": [{"hue": "#FBFF00"},{"saturation": -78},{"lightness": 39.19999999999999},{"gamma": 1}]},{"featureType": "road.local","stylers": [{"hue": "#00FFFD"},{"saturation": 0},{"lightness": 0},{"gamma": 1}]},{"featureType": "water","stylers": [{"hue": "#007FFF"},{"saturation": -77.41935483870967},{"lightness": -14.599999999999994},{"gamma": 1}]},{"featureType": "poi","stylers": [{"hue": "#007FFF"},{"saturation": -77.41935483870967},{"lightness": 42.79999999999998},{"gamma": 1}]}],
            
            'style9':  [{"featureType": "water","elementType": "geometry.fill","stylers": [{"color": "#A3C6FE"}]}, {"featureType": "transit","stylers": [{"color": "#b3C6FE"}, {"visibility": "off"}]}, {"featureType": "road.highway","elementType": "geometry.stroke","stylers": [{"visibility": "on"}, {"color": "#EBCE7B"}]}, {"featureType": "road.highway","elementType": "geometry.fill","stylers": [{"color": "#ffffff"}]}, {"featureType": "road.local","elementType": "geometry.fill","stylers": [{"visibility": "on"}, {"color": "#ffffff"}, {"weight": 1.8}]}, {"featureType": "road.local","elementType": "geometry.stroke","stylers": [{"color": "#d7d7d7"}]}, {"featureType": "poi","elementType": "geometry.fill","stylers": [{"visibility": "on"}, {"color": "#ebebeb"}]}, {"featureType": "administrative","elementType": "geometry","stylers": [{"color": "#a7a7a7"}]}, {"featureType": "road.arterial","elementType": "geometry.fill","stylers": [{"color": "#ffffff"}]}, {"featureType": "road.arterial","elementType": "geometry.fill","stylers": [{"color": "#ffffff"}]}, {"featureType": "landscape","elementType": "geometry.fill","stylers": [{"visibility": "on"}, {"color": "#E9E5DC"}]}, {"featureType": "road","elementType": "labels.text.fill","stylers": [{"color": "#696969"}]}, {"featureType": "administrative","elementType": "labels.text.fill","stylers": [{"visibility": "on"}, {"color": "#737373"}]}, {"featureType": "poi","elementType": "labels.icon","stylers": [{"visibility": "off"}]}, {"featureType": "poi","elementType": "labels","stylers": [{"visibility": "off"}]}, {"featureType": "road.arterial","elementType": "geometry.stroke","stylers": [{"color": "#d6d6d6"}]}, {"featureType": "road","elementType": "labels.icon","stylers": [{"visibility": "off"}]}, {}, {"featureType": "poi","elementType": "geometry.fill","stylers": [{"color": "#dadada"}]
            }]
        };
        /*var latlng = $(targetmap).data("latlong");
        if (latlng!=='') {
            var latlng_array = latlng.split(',');
            var lat = latlng_array[0];
            var lng = latlng_array[1];
            var latlng = new google.maps.LatLng(lat, lng);
        } else {
            var latlng = new google.maps.LatLng(0, 0);
        }*/
				$(targetmap).each(function() {
        	var map_style = $(this).data("mapstyle");
					$(this).prettyMaps({
							address: $(this).data("address"),
							image: $(this).data("marker"),
							hue: '#333',
							saturation: -100,
							zoom: $(this).data("zoom"),
							//center: latlng,
							draggable: true,
							panControl: false,
							zoomControl: true,
							mapTypeControl: false,
							scaleControl: false,
							streetViewControl: true,
							overviewMapControl: false,
							scrollwheel: false,
							styles: ThemeMascot_googlemap_styles[map_style]
					});
				});
    }
		//auto loaded maps:
		thememascot_showMap('.map-canvas');


    /* ---------------------------------------------------------------------- */
    /* ----------------------- 38 - toggle Google map ----------------------- */
    /* ---------------------------------------------------------------------- */
    function thememascot_toggleMap() {
        $(document).on('click', '.toggle-map', function(e) {
            $(this).toggleClass('open');
            var targetmap = $(this).data("targetmap");
            console.log(targetmap);
            $(targetmap).slideToggle(300, function() {
                thememascot_showMap(targetmap);
                if ($(targetmap).is(":visible")) {
                    setTimeout(function() {
                        $("html, body").animate({
                            scrollTop: $(".toggle-map").offset().top - 70
                        }, "slow", "easeInBack");
                    }, 300);
                }
            });
            return false;
        });

        $(document).on('click', '.btn-show-map', function(e) {
            $(this).addClass('fadeOut').animate({
                opacity: 0
            }, 500, function() {
                thememascot_showMap($(this).data("targetmap"));
            });
            return false;
        });
    }

})(jQuery);