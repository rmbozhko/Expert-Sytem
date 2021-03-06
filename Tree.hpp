#ifndef TREE_HPP
# define TREE_HPP

// #include "Node.hpp"
#include "Operation.hpp"
#include "Fact.hpp"
#include <map>
#include <string>
#include <iostream>

namespace ast
{
	// class Visitor
	// {
	// 	public:
	// 		Visitor() {};
	// 		~Visitor() {};
	// 		bool			visitAst(const Node* root, std::map<std::string, bool>& factsStrg);
	// 		void			visitDeleteAst(const Node* root); // visit all nodes of Ast and recursively delete all created Node-s
	// 		void			visitGraphAst(const Node* root, std::string& xdot_str) const; // grasp info xdot file to be visualized in form of graph
	// 		static bool		evaluate_expr(const std::string oper, bool lfact, bool rfact = false);
	// };

	class Tree
	{
		public:
			Tree(const Operation* root, std::map<std::string, Fact*>& factsStrg);
			~Tree() {};
			const Operation*		GetRoot() const;

		private:
			const Operation*		root_;
	};
}

#endif