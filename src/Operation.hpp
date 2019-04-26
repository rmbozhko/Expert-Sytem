#ifndef OPERATION_HPP
#define OPERATION_HPP

#include "Node.hpp"
#include "ExprSysEnums.hpp"
#include <array>
#include <string>

class Operation : public Node
{
public:
	Operation();
	Operation(const std::string oper_label = "", Node* lchild = nullptr, Node* rchild = nullptr);
	~Operation() {};

	virtual Node*						GetChild( const size_t pos ) const;
	const std::string			GetLabel( void ) const;

    virtual void Assign( Node* lfact, factValues& value );
    virtual void Assign( factValues& value, Node* node );
    virtual void Assign( Node* lfact, Node* rfact, factValues& value );

    virtual factValues Evaluate( factValues lfact, factValues rfact );
    virtual factValues Evaluate( factValues fact );
    virtual factValues Evaluate( factValues lvalue, Node* node );

private:
	std::array<Node*, 2>		children_;
	const std::string				oper_label_;
};

#endif
