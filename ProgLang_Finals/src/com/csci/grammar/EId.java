package com.csci.grammar; // Java Package generated by the BNF Converter.

import com.csci.visitor.EvalVisitor;
import com.csci.visitor.PrintVisitor;

public class EId extends Exp {

    public String id_;

    public EId(String p1) {
        id_ = p1;
    }

    @Override
    public String accept(PrintVisitor visitor) {
        return visitor.visit(this);
    }

    @Override
    public CustomObject eval(EvalVisitor visitor) throws Exception {
        return visitor.visit(this);
    }

}