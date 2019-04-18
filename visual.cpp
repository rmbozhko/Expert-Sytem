static void		ft_parse_rule(ExprSys::Node* rule, std::string& result, std::map<std::string, ExprSys::Fact*> factsStrg)
{
	if (rule->GetType() == ExprSys::nodeType::operation_t)
	{
		ExprSys::Operation*	oper = dynamic_cast<ExprSys::Operation*>(rule);

		result += std::to_string(oper->GetId()) + " [ shape=box, label=\"" + oper->GetLabel() + "\"]\n";
		result += std::to_string(oper->GetId()) + " -> " + std::to_string(oper->GetChild(0)->GetId()) + ";\n";
		if (oper->GetChild(1) != nullptr) // for binary operations(+, |)
		{
			result += std::to_string(oper->GetId()) + " -> " + std::to_string(oper->GetChild(1)->GetId()) + ";\n";
			ft_parse_rule(oper->GetChild(0), result, factsStrg);
			ft_parse_rule(oper->GetChild(1), result, factsStrg);
		}
		else // for unary operations(!)
			ft_parse_rule(oper->GetChild(0), result, factsStrg);	
	}
	else
	{
		ExprSys::Fact*	fact = dynamic_cast<ExprSys::Fact*>(rule);

		result += std::to_string(fact->GetId()) + " [ label=\"Fact: " + fact->GetKey() + "\nValue: \"";
		if (fact->GetValue() == ExprSys::factValues::False)
			result += "False\", color=\"red\"]\n";
		else if (fact->GetValue() == ExprSys::factValues::True)
			result += "True\", color=\"green\"]\n";
		else
			result += "Undetermined\", color=\"blue\"]\n";
	}
}

void			ft_print_dot(std::vector<ExprSys::Tree*>& treeStrg, std::map<std::string, ExprSys::Fact*> factsStrg)
{
	static size_t		status_num = 0;
	std::string			filename = "rules/status_" + std::to_string(status_num++) + ".dot";
	std::ofstream		file(filename);
	std::string			result = "digraph a {\n";

	if (!file.is_open())
	{
		std::cerr << "Fail while working with a file." << std::endl;
		exit(-1);
	}
	
	for (size_t i = 0; i < treeStrg.size(); ++i)
	{
		result += "Root -> " + std::to_string(treeStrg[i]->GetRoot()->GetId()) + ";\n";
		ft_parse_rule(treeStrg[i]->GetRoot(), result, factsStrg);
		file << result;
		file << "}\n";
	}
	file.close();
}