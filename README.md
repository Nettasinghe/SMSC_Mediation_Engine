# SMSC_Mediation_Engine

Telco Switch Mediation Engine for Sema SMSC.

Telecom Switches such as MSCs, GGSNs, SMSC sand VAS servers store subscribers Call Detail Record (CDR) data in encoded formats of either proprietary or ASN.1. Switch Mediation Engine functions as the intermediary between the Telco Network and the Billing System by decoding the CDRs and transforming (amalgamating, stitching and enhancing) them to the input format expected by the Billing System. SMSC Mediation Engine decodeds Sema SMSC CDRs in a proprietary binary format.

mediation.cpp file contains the main method of this module.
