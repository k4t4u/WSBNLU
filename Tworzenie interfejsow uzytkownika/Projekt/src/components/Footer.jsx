import { motion } from 'framer-motion';

export default function Footer() {
    return (
        <motion.footer
            initial={{ opacity: 0, y: 10 }}
            animate={{ opacity: 1, y: 0 }}
            transition={{ duration: 0.5 }}
            className="bg-gray-900 dark:bg-gray-800 text-white py-4 text-center"
        >
            &copy; {new Date().getFullYear()} Magazyn części samochodowych – Wszystkie prawa zastrzeżone.
        </motion.footer>
    );
}
