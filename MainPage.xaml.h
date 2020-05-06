//
// MainPage.xaml.h
// MainPage 类的声明。
//

#pragma once

#include "MainPage.g.h"

#include <iostream>
#include <windows.h>
#include <list>

#include "HomePage.xaml.h"
#include "AppStorePage.xaml.h"
#include "LibraryPage.xaml.h"
#include "DeveloperCenterPage.xaml.h"
#include "UserPage.xaml.h"
#include "SettingsPage.xaml.h"

namespace MicroLightHome
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();


	
	private:
		 
		void NavView_Navigate(std::string navItemTag, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo transitionInfo);
		void NavView_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NavView_ItemInvoked(Windows::UI::Xaml::Controls::NavigationView^ sender, Windows::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs^ args);
		void NavView_BackRequested(Windows::UI::Xaml::Controls::NavigationView^ sender, Windows::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs^ args);
		void OnNavigated(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationEventArgs ^e);
		Windows::UI::Xaml::Interop::TypeName SelectedItemTypeName;
		Windows::UI::Xaml::Interop::TypeName  ItemsTypeName[6] =
		{ Windows::UI::Xaml::Interop::TypeName(HomePage::typeid) ,
		 Windows::UI::Xaml::Interop::TypeName(AppStorePage::typeid),
		 Windows::UI::Xaml::Interop::TypeName(LibraryPage::typeid),
		 Windows::UI::Xaml::Interop::TypeName(DeveloperCenterPage::typeid),
		
		 Windows::UI::Xaml::Interop::TypeName(SettingsPage::typeid),
			Windows::UI::Xaml::Interop::TypeName(UserPage::typeid)};
	
	};
}
