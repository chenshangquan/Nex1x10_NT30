#pragma once
#include <string>
#include <memory>
#include <map>
using namespace std;

#define NS_TEMPLATECLASS_BEGIN namespace TemplateClass{
#define NS_TEMPLATECLASS_END	}
#define US_NS_TEMPLATECLASS using namespace TemplateClass;

#define DEF_MEMBER( type, name, funcname) \
	protected: type name;\
	public: virtual type get##funcname(){return name;} \
	public: virtual void set##funcname(type var){ name = var; }

NS_TEMPLATECLASS_BEGIN
/*
	����ָ�����
*/
class CDelegateBase    
{
public:
	CDelegateBase(void* pObject, void* pFn) : m_pObject( pObject ),m_pFn(pFn){	}
	CDelegateBase(const CDelegateBase& rhs){
		m_pObject = rhs.m_pObject;
		m_pFn = rhs.m_pFn; 
	}
	virtual ~CDelegateBase(){}
	bool Equals(const CDelegateBase& rhs) const{
		return m_pObject == rhs.m_pObject && m_pFn == rhs.m_pFn; 
	}
	bool operator() (void* param){
		return Invoke(param); 
	}
	virtual CDelegateBase* Copy() const = 0; 

protected:
	void* GetFn(){return m_pFn;}
	void* GetObject(){return m_pObject;}
	virtual bool Invoke(void* param) = 0;

private:
	void* m_pObject;
	void* m_pFn;
};

/*
	��̬����ָ�롢C����ָ��
*/
class CDelegateStatic: public CDelegateBase
{
	typedef bool (*Fn)(void*);
public:
	CDelegateStatic(Fn pFn) : CDelegateBase(NULL, pFn) { } 
	CDelegateStatic(const CDelegateStatic& rhs) : CDelegateBase(rhs) { } 
	virtual CDelegateBase* Copy() const { return new CDelegateStatic(*this); }

protected:
	virtual bool Invoke(void* param){
		Fn pFn = (Fn)GetFn();
		return (*pFn)(param); 
	}
};

/*
	��Ա������ָ��
*/
template <class T> class CDelegate : public CDelegateBase
{
	typedef bool (T::* Fn)(void*);
public:
	CDelegate(T* pObj, Fn pFn) : CDelegateBase(pObj, &pFn), m_pFn(pFn) { }
	CDelegate(const CDelegate& rhs) : CDelegateBase(rhs) { m_pFn = rhs.m_pFn; } 
	virtual CDelegateBase* Copy() const { return new CDelegate(*this); }

protected:
	virtual bool Invoke(void* param){
		T* pObject = (T*) GetObject();
		return (pObject->*m_pFn)(param); 
	}  

private:
	Fn m_pFn;
};

/*
	ָ�������������࣬�����죬����ָ��
	�ڲ�ʵ��Ϊmap��KeyΪ��ֵ��DataΪ��������
	ʹ������Ҫ�������࣬ʵ��add����
	�ⲿʹ��ָ���ʹ��weak_ptr����ָ֤�밲ȫ��
*/
template<class Key,class Data,class Type = string> class IContainer_SharePtr
{
protected:
	typedef map<Key,shared_ptr<Data> > Container;
	Container m_mapData;
public:
	/*
		����ʵ�ָú�������������������Ҳ�ǹ���
	*/
	virtual weak_ptr<Data> add( const Key& key, const Type& strType = "") = 0;
	
	virtual ~IContainer_SharePtr(){}

	virtual bool get(const Key& key, weak_ptr<Data>& result){
		Container::iterator itr = m_mapData.find( key );
		if ( itr != m_mapData.end() ){
			result = itr->second;
			return true;
		}
		return false;
	}

	virtual bool remove( const Key& key ){
		Container::iterator itr = m_mapData.find( key );
		if ( itr != m_mapData.end() ){
			itr->second.reset();
			m_mapData.erase( itr );
			return true;
		}
		return false;
	}

	virtual void removeall(){
		Container::iterator itr = m_mapData.begin();
		while ( itr != m_mapData.end() ){
			itr->second.reset();	
			itr++;
		}
		m_mapData.clear();
	}

	unsigned int count(){
		return m_mapData.size();
	}

	virtual void traversal( CDelegateBase* pFun ){
		Container::iterator itr = m_mapData.begin();
		while ( itr != m_mapData.end() ){
			//	weak_ptr<Data> ptr( itr->second );
			if ( (*pFun)((void*)itr->second._Get()) == false ){
				return;
			}
			itr++;
		}
	} 
};

template<class Key,class Data> class IContainer_Struct
{
protected:
	typedef map<Key,Data> Container;
	Container m_mapData;
public:
	virtual void add( const Key& key, const Data& data ){
		m_mapData[key] = data;
	}
	virtual ~IContainer_Struct(){}

	virtual bool get(const Key& key, Data data){
		Container::iterator itr = m_mapData.find( key );
		if ( itr != m_mapData.end() ){
			data = itr->second;
			return true;
		}
		return false; 
	}

	virtual bool remove( const Key& key ){
		Container::iterator itr = m_mapData.find( key );
		if ( itr != m_mapData.end() ){
			m_mapData.erase( itr );
			return true;
		}
		return false;
	}

	virtual void removeall(){
		m_mapData.clear();
	}
	unsigned int count(){
		return m_mapData.size();
	}

	virtual void traversal( CDelegateBase* pFun ){
		Container::iterator itr = m_mapData.begin();
		while ( itr != m_mapData.end() ){
			if ( (*pFun)( (void*)(&(itr->second)) ) == false ){
				return;
			}
			itr++;
		}
	} 
};

NS_TEMPLATECLASS_END
