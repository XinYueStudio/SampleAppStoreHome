//
// MainPage.xaml.cpp
// MainPage 类的实现。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace MicroLightHome;
using namespace std;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板

using namespace Windows::UI::Xaml::Media::Animation;

//TypeName  for Frame Navigate
using namespace Windows::UI::Xaml::Interop;

 
MainPage::MainPage()
{


	InitializeComponent();

	 
}


 

void MicroLightHome::MainPage::NavView_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// Add handler for ContentFrame navigation.
	ContentFrame->Navigated += ref new Windows::UI::Xaml::Navigation::NavigatedEventHandler(this, &MicroLightHome::MainPage::OnNavigated);

	// NavView doesn't load any page by default, so load home page.
	NavView->SelectedItem = NavView->MenuItems->GetAt(0);
 
	// If navigation occurs on SelectionChanged, this isn't needed.
   // Because we use ItemInvoked to navigate, we need to call Navigate
   // here to load the home page.
    // Get the page type before navigation so you can prevent duplicate
	// entries in the backstack.
	Windows::UI::Xaml::Interop::TypeName preNavPageType = ContentFrame->CurrentSourcePageType;
	  SelectedItemTypeName = ItemsTypeName[0];
	// Only navigate if the selected page isn't currently loaded.
	if (preNavPageType.Name!=SelectedItemTypeName.Name)
	{
		ContentFrame->Navigate(SelectedItemTypeName,this);
	}
  
}



void MicroLightHome::MainPage::NavView_ItemInvoked(Windows::UI::Xaml::Controls::NavigationView^ sender, Windows::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs^ args)
{
	if (args->InvokedItemContainer)
	{

		String^ ItemName = args->InvokedItemContainer->Name;
		int SelectIndex = 0;
		if (ItemName == L"Home")
		{
			SelectIndex = 0;
		}
		else if (ItemName == L"AppStore")
		{
			SelectIndex = 1;
		}
		else if (ItemName == L"Library")
		{
			SelectIndex = 2;
		}
		else if (ItemName == L"DeveloperCenter")
		{
			SelectIndex = 3;
		}
		else if (ItemName == L"Settings")
		{
			SelectIndex = 4;
		}
		else if (ItemName == L"User")
		{
			SelectIndex = 5;
		}

		Windows::UI::Xaml::Interop::TypeName NewSelectedItemTypeName = ItemsTypeName[SelectIndex];

		// Only navigate if the selected page isn't currently loaded.
		if (NewSelectedItemTypeName.Name != SelectedItemTypeName.Name)
		{
			SelectedItemTypeName = NewSelectedItemTypeName;
			ContentFrame->Navigate(SelectedItemTypeName, this);

			if (ContentFrame->CanGoBack)
			{
				NavView->IsBackButtonVisible = NavigationViewBackButtonVisible::Visible;
				NavView->IsBackEnabled = true;
			}
		}
		 
	}
}


void MicroLightHome::MainPage::NavView_BackRequested(Windows::UI::Xaml::Controls::NavigationView^ sender, Windows::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs^ args)
{
	if (ContentFrame->CanGoBack)
	{
		 
		ContentFrame->GoBack();
	
		SelectedItemTypeName = ContentFrame->CurrentSourcePageType;

		for (int i = 0; i < 6; i++)
		{
			Windows::UI::Xaml::Interop::TypeName NewSelectedItemTypeName = ItemsTypeName[i];
			if (NewSelectedItemTypeName.Name == SelectedItemTypeName.Name)
			{
				int SelectIndex = i;			 
				NavView->SelectedItem=	NavView->MenuItems->GetAt(SelectIndex);
				break;
			}
		}
	}
	else
	{
		NavView->IsBackEnabled = false;
	}
}


void MicroLightHome::MainPage::OnNavigated(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationEventArgs ^e)
{
	 
}
